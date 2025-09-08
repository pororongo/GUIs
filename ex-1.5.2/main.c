#include <SDL2/SDL.h>
#include <stdlib.h>

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
    Uint32 agora = SDL_GetTicks();
    int isevt = SDL_WaitEventTimeout(evt, *ms);

    Uint32 delta = (SDL_GetTicks() - agora);
    *ms -= delta;

    if(delta > *ms){
    	*ms = 0;
    }
    
    return isevt;
}

int main (int argc, char* args[]) {

    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo três retângulos",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 250, SDL_WINDOW_SHOWN);

    /* criando os retangulos*/
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    SDL_Rect r = { 90,125, 10,10 };

    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren, &r);

    SDL_Rect r_time = { 240,125, 10,10 };

    SDL_SetRenderDrawColor(ren, 255,255,0,1);
    SDL_RenderFillRect(ren, &r_time);

    SDL_Rect r_mouse = { 390,125, 10,10 };

    SDL_SetRenderDrawColor(ren, 255,0,0,1);
    SDL_RenderFillRect(ren, &r_mouse);


    SDL_Event evt;

    Uint32 antes = SDL_GetTicks();
    Uint32 agora;
    int espera = 10;
    float delta;
    int vel;

    while (1) {
	agora = SDL_GetTicks();
        delta = (agora - antes) / 1000.0f;
        antes = agora;

	vel = 80;
        int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
	if(isevt){
	    /* finalizacao alt+f4*/
            const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
            if(currentKeyStates[ SDL_SCANCODE_LALT ]
               && currentKeyStates[ SDL_SCANCODE_F4 ]){
                SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
                SDL_Quit();
                exit(EXIT_SUCCESS);
            }

            /* finalizacao x janela*/
            if (evt.type == SDL_WINDOWEVENT){
                if(evt.window.event == SDL_WINDOWEVENT_CLOSE){
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    exit(EXIT_SUCCESS);
                }
            }

	    /*movendo o retangulo pelo mouse*/
            int x_m,y_m;

            if (evt.type == SDL_MOUSEMOTION){
                SDL_GetMouseState(&x_m, &y_m);
                r_mouse.x = x_m;
                r_mouse.y = y_m;
            }

	    /* movendo pelo teclado */
	    switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if(r.y >= 5){
                        r.y -= 5;
                    }
                    break;
                case SDLK_DOWN:
                    if(r.y <= 235){
                        r.y += 5;
                    }
                    break;
                case SDLK_LEFT:
                    if(r.x >= 5){
                        r.x -= 5;
                    }
                    break;
                case SDLK_RIGHT:
                    if(r.x <= 490){
                        r.x += 5;
                    }
                    break;

            }

	    r_time.x += vel * delta;
	    r_time.x %= 500;
	} else {
	    espera = 10;
	    r_time.x += vel * delta;
	    r_time.x %= 500;
	}    

       /*atualizando os retangulos*/

        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
        SDL_RenderFillRect(ren, &r);
        
        SDL_SetRenderDrawColor(ren, 255,255,0,1);
        SDL_RenderFillRect(ren, &r_time);

	SDL_SetRenderDrawColor(ren, 255,0,0,1);
	SDL_RenderFillRect(ren, &r_mouse);

        SDL_RenderPresent(ren);
        SDL_Delay(16);

    }

}
