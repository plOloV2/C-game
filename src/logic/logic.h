#include <stdlib.h>

struct gameState{
    uint16_t keyboardInputs;
    uint16_t scene;
    uint8_t quit;
};

struct gameState* initGameState(){
    struct gameState* result = (struct gameState*) malloc(sizeof(uint16_t)*2 + sizeof(uint8_t));
    if(result == NULL)
        return NULL;

    result->quit = 0;
    result->scene = 0;

    return result;
}

void keyboardInputs(struct gameState* game){
    


}