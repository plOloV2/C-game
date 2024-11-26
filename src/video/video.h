#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

int initIMG(){
    return !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG);
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