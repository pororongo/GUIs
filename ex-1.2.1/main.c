#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Mar de noite e barco",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_Rect lua = {425,50, 150,150};
    SDL_RenderFillRect(ren, &lua);

    SDL_SetRenderDrawColor(ren, 159, 158, 199, 1);
    SDL_Rect nuvem = {510,120, 140,90};
    SDL_RenderFillRect(ren, &nuvem);
    SDL_SetRenderDrawColor(ren, 118, 118, 149, 1);
    SDL_Rect nuvemsombra = {510, 190, 140,20};
    SDL_RenderFillRect(ren, &nuvemsombra);

    SDL_SetRenderDrawColor(ren, 164, 122, 82, 1);
    SDL_Rect barco = {450,350, 150, 50};
    SDL_RenderFillRect(ren, &barco);

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0x00);
    SDL_Rect mastro = {515,280, 10,70};
    SDL_RenderFillRect(ren, &mastro);

    SDL_SetRenderDrawColor(ren, 255, 255, 255, 0x00);
    SDL_Rect vela = {525,280, 50,30};
    SDL_RenderFillRect(ren, &vela);

    SDL_SetRenderDrawColor(ren, 1, 0, 59, 0x00);
    SDL_Rect mar = {0,400, 1000,100};
    SDL_RenderFillRect(ren, &mar);

    /* farol */
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_Rect listra1b = {70,350, 170,50};
    SDL_RenderFillRect(ren, &listra1b);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 0x00);
    SDL_Rect listra1v = {70,300, 170,50};
    SDL_RenderFillRect(ren, &listra1v);

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_Rect listra2b = {70,250, 170,50};
    SDL_RenderFillRect(ren, &listra2b);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 0x00);
    SDL_Rect listra2v = {70,200, 170,50};
    SDL_RenderFillRect(ren, &listra2v);

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_Rect listra3b = {70,150, 170,50};
    SDL_RenderFillRect(ren, &listra3b);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 0x00);
    SDL_Rect listra3v = {70,100, 170,50};
    SDL_RenderFillRect(ren, &listra3v);

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_Rect listralb = {55,100, 200,20};
    SDL_RenderFillRect(ren, &listralb);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 0x00);
    SDL_Rect topofarol = {80,20, 150,80};
    SDL_RenderFillRect(ren, &topofarol);

    SDL_SetRenderDrawColor(ren, 255, 255, 0, 0x00);
    SDL_Rect janelafarol = {130,50, 50,50};
    SDL_RenderFillRect(ren, &janelafarol);


    SDL_RenderPresent(ren);
    SDL_Delay(5000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
 }
