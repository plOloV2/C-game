#include <stdlib.h>
struct Object
{
    uint8_t posX;
    uint8_t posY;
    
    char* name;

    // pointer to sprites

    struct Entity* statistics;
};

struct Object* NewObject(char* name, uint8_t posX, uint8_t posY){
    struct Object* result = (struct Object*) malloc(sizeof(uint8_t)*2 + sizeof(char*) + sizeof(struct Entity*));

    result->posX = posX;
    result->posY = posY;
    result->name = name;
    result->statistics = NULL;
    // result-> pointer to spirites = 

    return result;
}