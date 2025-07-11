#include <SDL3_image/SDL_image.h>

int initSDL(SDL_Window** window, SDL_Renderer** renderer){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) <= 0){
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

	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
		SDL_Log( "SDL_image error: %s\n", SDL_GetError() );
        return -4;
	}

    return 0;
}

SDL_Texture* loadTexture(char* texturePath, SDL_Renderer** renderer){
    SDL_Texture* resultTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(texturePath);
    if(loadedSurface == NULL){
        SDL_Log("Loading %s failed! IMG_Load() error: %s", texturePath, SDL_GetError());
        return NULL;
    }

    resultTexture = SDL_CreateTextureFromSurface(*renderer, loadedSurface);
    if(resultTexture == NULL)
        SDL_Log("SDL_CreateTextureFromSurface() error: %s", SDL_GetError());

    SDL_DestroySurface(loadedSurface);

    return resultTexture;
}