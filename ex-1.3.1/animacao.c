#include <SDL2/SDL.h>
int main (int argc, char* args[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("Animacao", 
					   SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED, 
					   250, 150, SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	SDL_Rect r = {50,20, 50,50};
	while(1){
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0x00);
		SDL_RenderFillRect(ren, &r);
		SDL_RenderPresent(ren);
		SDL_Delay(500);
		
		if(r.x <= 100 && r.y <= 20){
		   	r.x += 5;
		}
		if(r.x >= 100 && r.y < 60){
			r.y += 5;
		}
		if(r.x > 50 && r.y >= 60){
			r.x -= 5;
		}
		if(r.x <= 50 && r.y > 20){
			r.y -= 5;
		}
	
	}
		
}
