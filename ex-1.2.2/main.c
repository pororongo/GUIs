#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main(int argc, char* args[]){
/* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Desenho 2",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(ren, 255,255,255,0x00);
    SDL_RenderClear(ren);

	/* mascara de lilith*/

    aatrigonColor(ren, 100, 350, 180, 140, 20, 140, 0xFFff3bb8);

    lineColor(ren, 100, 140, 100, 350,  0xFFff3bb8);


    ellipseColor(ren, 50, 170, 40, 10, 0xFFff3bb8);
    circleColor(ren, 50, 170, 10, 0xFFff3bb8);


    ellipseColor(ren, 50, 210, 40, 10, 0xFFff3bb8);
    circleColor(ren, 50, 210, 10, 0xFFff3bb8);


    ellipseColor(ren, 50, 250, 40, 10, 0xFFff3bb8);
    circleColor(ren, 50, 250, 10, 0xFFff3bb8);


    ellipseColor(ren, 150, 290, 40, 10, 0xFFff3bb8);
    circleColor(ren, 150, 290, 10, 0xFFff3bb8);

    ellipseColor(ren, 150, 250, 40, 10, 0xFFff3bb8);
    circleColor(ren, 150, 250, 10, 0xFFff3bb8);

    ellipseColor(ren, 150, 210, 40, 10, 0xFFff3bb8);
    circleColor(ren, 150, 210, 10, 0xFFff3bb8);

    ellipseColor(ren, 150, 170, 40, 10, 0xFFff3bb8);
    circleColor(ren, 150, 170, 10, 0xFFff3bb8);

    stringColor(ren, 150, 350, "Mascara de Lilith", 0xFF000000);

    stringColor(ren, 150, 370, "de Neon Genesis Evangelion", 0xFF000000);

	/* bandeira do japao*/

    filledCircleColor(ren, 500, 250, 150, 0xff0000ff);

    stringColor(ren, 400, 450, "Essa eh a bandeira do Japao", 0xFF000000);

	/* sushi */

    roundedRectangleColor(ren, 750, 150, 950, 350, 50, 0xFF000000);
    roundedBoxColor(ren, 800, 200, 900, 300, 30, 0xFF748bfc);
    stringColor(ren, 800, 400, "Sushi de Salmao", 0xFF000000);

    SDL_RenderPresent(ren);
    SDL_Delay(5000);
}
