#include "audio/audio.h"
#include "video/video.h"
#include "logic/logic.h"

int initSDL(SDL_Window** window, SDL_Renderer** renderer){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) < 0){
        SDL_Log("SDL_INIT error: %s", SDL_GetError());
        return -1;
    }

    *window = SDL_CreateWindow("Gra", 800, 600, 0);
    if(*window == NULL){
        SDL_Log("SDL_CreateWindow error: %s", SDL_GetError());
        return -2;
    }

    *renderer = SDL_CreateRenderer(*window, NULL);
    if(*renderer == NULL){
        SDL_Log("SDL_CreateRenderer error: %s", SDL_GetError());
        return -3;
    }

	if(initIMG()){
		SDL_Log( "SDL_image error: %s\n", SDL_GetError() );
        return -4;
	}

    return 0;
}

void updateGameState();

void updateScreen(SDL_Renderer** renderer);

void uppdateAudio();

SDL_Texture* loadTexture(char* texturePath, SDL_Renderer** renderer);
