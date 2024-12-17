#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "audio/audio.h"
#include "video/video.h"
#include "logic/logic.h"
#include "input/input.h"

void closeGame(SDL_Window** window, SDL_Renderer** renderer){
    SDL_Log("Game closes");
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);

    SDL_Quit();
}
