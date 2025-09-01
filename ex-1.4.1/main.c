#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct {
    int x, y;
    } ret;

SDL_Color cores[10] = {{255,0,0,1},     //vermelho
                       {0,255,0,1},     //verde
                       {255,255,0,1},   //amarelo
                       {255,0,255,1},   //magenta
                       {0,255,255,1},   //ciano
                       {166,83,50,1},   //marrom
                       {0,0,0,1},       //preto
                       {125,125,125,1}, //cinza
                       {255,125,0,1},   //laranja
                       {125,0,125,1}};  //roxo
					

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    ret lista_pos[10];
    int cont_rets;

    SDL_Rect r = { 40,20, 10,10 };

    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren, &r);

    SDL_RenderPresent(ren);

    SDL_Event evt;

    while (1) {
        SDL_WaitEvent(&evt);
	if (evt.type == SDL_WINDOWEVENT){
	    if(evt.window.event == SDL_WINDOWEVENT_CLOSE){
         	SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
                SDL_Quit();
                exit(EXIT_SUCCESS);
	    }
	}
	
	if (evt.type == SDL_MOUSEBUTTONDOWN){
	    if (cont_rets < 10){
		SDL_GetMouseState(&lista_pos[cont_rets].x, 
				  &lista_pos[cont_rets].y);	
		cont_rets += 1;
	    }
        }

        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
		    if(r.y >= 5){
                        r.y -= 5;
		    }
                    break;
                case SDLK_DOWN:
		    if(r.y <= 85){
                        r.y += 5;
		    }
                    break;
                case SDLK_LEFT:
		    if(r.x >= 5){
                        r.x -= 5;
		    }
                    break;
                case SDLK_RIGHT:
		    if(r.x <= 185){
                    	r.x += 5;
		    }
                    break;
              /* FINALIZACAO */
		case SDLK_LALT && SDLK_F4:
	      	    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    exit(EXIT_SUCCESS);
	    
	    }
	
        }
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
        SDL_RenderFillRect(ren, &r);


        for(int i = 0; i < cont_rets; i++){
            SDL_Color cor_atual = cores[i];

            SDL_SetRenderDrawColor(ren, cor_atual.r,
            cor_atual.g, cor_atual.b, cor_atual.a);
            SDL_Rect ret_atual = {lista_pos[i].x, lista_pos[i].y, 10,10};
            SDL_RenderFillRect(ren, &ret_atual);
        }

        SDL_RenderPresent(ren);
        SDL_Delay(16);

    }

}
