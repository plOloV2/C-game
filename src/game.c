#include "game.h"

int main(){

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    int initCheck = initSDL(&window, &renderer);
    if(initCheck != 0)
        return initCheck;

    SDL_Event event;
    unsigned char quit = 0;
    while(!quit){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_EVENT_QUIT:
                    quit = 1;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if(event.key.key == SDLK_ESCAPE)
                        quit = 1;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0xff, 0xff, 0xff);
        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    SDL_Log("Game closes");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}