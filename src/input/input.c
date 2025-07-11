#include "input_lib.h"

struct Inputs* initInputs(){

    struct Inputs* result = calloc(1, sizeof(struct Inputs));

    if(!result)
        SDL_Log("Inputs struct alocation failed");

    return result;
    
}

void eventHandler(struct Inputs* game, SDL_Event event){

    game->keysPressed &= ~(1 << MOUSE_LEFT_KEY_FREE);
    game->keysPressed &= ~(1 << MOUSE_RIGHT_KEY_FREE);

    while(SDL_PollEvent(&event)){                               //loops untill all events are processed
    
        switch(event.type){
            case SDL_EVENT_QUIT:
                game->quit = 1;
                break;

            case SDL_EVENT_KEY_DOWN:                            //key press detection
                switch(event.key.key){
                    case SDLK_ESCAPE:
                        game->keysPressed |= (1 << KEY_PRESS_ESCAPE);
                        break;

                    case SDLK_RETURN:
                        game->keysPressed |= (1 << KEY_PRESS_ENTER);
                        break;
                    
                    case SDLK_SPACE:
                        game->keysPressed |= (1 << KEY_PRESS_SPACE);
                        break;

                    case SDLK_E:
                        game->keysPressed |= (1 << KEY_PRESS_ACTION1);
                        break;
                    
                    case SDLK_Q:
                        game->keysPressed |= (1 << KEY_PRESS_ACTION2);
                        break;

                    case SDLK_LSHIFT:
                        game->keysPressed |= (1 << KEY_PRESS_SHIFT);
                        break;

                    case SDLK_RSHIFT:
                        game->keysPressed |= (1 << KEY_PRESS_SHIFT);
                        break;

                    case SDLK_W:
                        game->keysPressed |= (1 << KEY_PRESS_UP);
                        break;

                    case SDLK_S:
                        game->keysPressed |= (1 << KEY_PRESS_DOWN);
                        break;

                    case SDLK_A:
                        game->keysPressed |= (1 << KEY_PRESS_LEFT);
                        break;

                    case SDLK_D:
                        game->keysPressed |= (1 << KEY_PRESS_RIGHT);
                        break;

                    case SDLK_UP:
                        game->keysPressed |= (1 << KEY_PRESS_UP);
                        break;

                    case SDLK_DOWN:
                        game->keysPressed |= (1 << KEY_PRESS_DOWN);
                        break;

                    case SDLK_LEFT:
                        game->keysPressed |= (1 << KEY_PRESS_LEFT);
                        break;

                    case SDLK_RIGHT:
                        game->keysPressed |= (1 << KEY_PRESS_RIGHT);
                        break;
                }
                break;

            case SDL_EVENT_KEY_UP:                              //key release detection
                switch(event.key.key){
                    case SDLK_ESCAPE:
                        game->keysPressed &= ~(1 << KEY_PRESS_ESCAPE);
                        break;

                    case SDLK_RETURN:
                        game->keysPressed &= ~(1 << KEY_PRESS_ENTER);
                        break;
                    
                    case SDLK_SPACE:
                        game->keysPressed &= ~(1 << KEY_PRESS_SPACE);
                        break;

                    case SDLK_E:
                        game->keysPressed &= ~(1 << KEY_PRESS_ACTION1);
                        break;
                    
                    case SDLK_Q:
                        game->keysPressed &= ~(1 << KEY_PRESS_ACTION2);
                        break;

                    case SDLK_LSHIFT:
                        game->keysPressed &= ~(1 << KEY_PRESS_SHIFT);
                        break;

                    case SDLK_RSHIFT:
                        game->keysPressed &= ~(1 << KEY_PRESS_SHIFT);
                        break;

                    case SDLK_W:
                        game->keysPressed &= ~(1 << KEY_PRESS_UP);
                        break;

                    case SDLK_S:
                        game->keysPressed &= ~(1 << KEY_PRESS_DOWN);
                        break;

                    case SDLK_A:
                        game->keysPressed &= ~(1 << KEY_PRESS_LEFT);
                        break;

                    case SDLK_D:
                        game->keysPressed &= ~(1 << KEY_PRESS_RIGHT);
                        break;

                    case SDLK_UP:
                        game->keysPressed &= ~(1 << KEY_PRESS_UP);
                        break;

                    case SDLK_DOWN:
                        game->keysPressed &= ~(1 << KEY_PRESS_DOWN);
                        break;

                    case SDLK_LEFT:
                        game->keysPressed &= ~(1 << KEY_PRESS_LEFT);
                        break;

                    case SDLK_RIGHT:
                        game->keysPressed &= ~(1 << KEY_PRESS_RIGHT);
                        break;
                }
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:                   //mouse button press detection
                switch(event.button.button){
                    case SDL_BUTTON_LEFT:
                        game->keysPressed |= (1 << MOUSE_KEY_PRESS_LEFT);
                        game->keysPressed |= (1 << MOUSE_LEFT_KEY_FREE);
                        break;

                    case SDL_BUTTON_RIGHT:
                        game->keysPressed |= (1 << MOUSE_KEY_PRESS_RIGHT);
                        game->keysPressed |= (1 << MOUSE_RIGHT_KEY_FREE);
                        break;
                }
                break;

            case SDL_EVENT_MOUSE_BUTTON_UP:                     //mouse button release detection
                switch(event.button.button){
                    case SDL_BUTTON_LEFT:
                        if(!(game->keysPressed & (1 << MOUSE_LEFT_KEY_FREE)))
                            game->keysPressed &= ~(1 << MOUSE_KEY_PRESS_LEFT);
                        break;

                    case SDL_BUTTON_RIGHT:
                        if(!(game->keysPressed & (1 << MOUSE_RIGHT_KEY_FREE)))
                            game->keysPressed &= ~(1 << MOUSE_KEY_PRESS_RIGHT);
                        break;
                }
                break;

            case SDL_EVENT_MOUSE_MOTION:                        //mouse motion detection
                SDL_GetMouseState(&game->mouseX, &game->mouseY);
                break;
        }

    }

}
