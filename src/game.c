#include "game.h"

int main(int argc, char *argv[]){

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    struct gameState* game = NULL;

    int initCheck = initSDL(&window, &renderer);
    if(initCheck != 0)
        return initCheck;

    game = initGameState();
    if(game == NULL)
        return -5;

    texture = loadTexture("../assets/textures/test.jpg", &renderer);

    if(texture == NULL)
        return -6;

    SDL_Event event;

    while(!game->quit){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_EVENT_QUIT:
                    game->quit = 1;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if(event.key.key == SDLK_ESCAPE)
                        game->quit = 1;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0xf0, 0xff, 0xff);
        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    closeGame(&window, &renderer);

    return 0;
}