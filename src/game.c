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
        
        eventHandler(game, event);

        SDL_SetRenderDrawColor(renderer, 0, 0xf0, 0xff, 0xff);
        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);
        SDL_Delay(1);
        SDL_Log("%i\nx:%f\ny:%f\n", game->keysPressed, game->mouseX, game->mouseY);

    }

    closeGame(&window, &renderer);

    return 0;
}
