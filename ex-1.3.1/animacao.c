#include <SDL2/SDL.h>
int main (int argc, char* args[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("Animacao", 
					   SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED, 
					   200, 100, SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	SDL_Rect r = {40,20, 10,10};
	while(1){
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0x00);
		SDL_RenderFillRect(ren, &r);
		SDL_RenderPresent(ren);
		SDL_Delay(500);
		
		if(r.x > 0){
			r.x -= 5;
		}
		if(r.x < 0){
			r.y -= 5;
		}
		if(r.x < 0 && r.y < 0){
			r.x += 5;
		}
		if(r.x > 0 && r.y < 0){
			r.y += 5;
		}
	}
		
}
