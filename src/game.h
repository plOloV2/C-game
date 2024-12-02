#include "audio/audio.h"
#include "video/video.h"
#include "logic/logic.h"

struct gameState;

struct gameState* initGameState();

int initSDL(SDL_Window** window, SDL_Renderer** renderer);

// void updateGameState(struct gameState* game);

// void updateScreen(SDL_Renderer** renderer, struct gameState* game);

// void uppdateAudio(struct gameState* game);

SDL_Texture* loadTexture(char* texturePath, SDL_Renderer** renderer);

void closeGame(SDL_Window** window, SDL_Renderer** renderer){
    SDL_Log("Game closes");
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);

    SDL_Quit();
}
