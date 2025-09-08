#include <SDL2/SDL.h>

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


int main (int argc, char* args[]){
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Window* win = SDL_CreateWindow("Animacao",
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED, 
                                           400, 400, SDL_WINDOW_SHOWN);
        SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

        SDL_Rect r = {50,20, 50,50};
        float vel = 50;

	int cont_cor = 0;
	SDL_Color cor_atual = cores[0];

	Uint32 espera = 100;
	Uint32 delta;
        while(1){
	    if(r.x <= 300 && r.y <= 20){
		r.x += vel*delta/1000;
	    }
	    if(r.x >= 300 && r.y < 300){
		r.y += vel*delta/1000;
	    }
	    if(r.x > 50 && r.y >= 300){
		r.x -= vel*delta/1000;
	    }
	    if(r.x <= 50 && r.y > 20){
		r.y -= vel*delta/1000;
	    }

            SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, cor_atual.r, cor_atual.g,
                                        cor_atual.b, cor_atual.a);
            SDL_RenderFillRect(ren, &r);
            SDL_RenderPresent(ren);

	    SDL_Event evt;
	    Uint32 antes = SDL_GetTicks();
	    int isevt = SDL_WaitEventTimeout(&evt, espera);
	    delta = (SDL_GetTicks() - antes);
	    if (isevt){
	        espera -= (SDL_GetTicks() - antes);
	        if(espera < 0){
	            espera = 0;
		}	  

		if (evt.type == SDL_WINDOWEVENT){
                    if(evt.window.event == SDL_WINDOWEVENT_CLOSE){
                        SDL_DestroyRenderer(ren);
                	SDL_DestroyWindow(win);
                	SDL_Quit();
                	exit(EXIT_SUCCESS);
            	    }
                }
 
		if(evt.type == SDL_KEYDOWN){
		    if (evt.key.keysym.sym == SDLK_c){
		        cont_cor += 1;
			cont_cor %= 10;
			cor_atual = cores[cont_cor];
		    }
		}

	    }else{
		espera = 100;
	    }

    }
}	
