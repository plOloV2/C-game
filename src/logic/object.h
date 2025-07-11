#ifndef OBJ_H
#define OBJ_H

#include <stdlib.h>
struct Object
{
    uint8_t id;

    uint8_t posX;
    uint8_t posY;
    
    char* name;

    // pointer to sprites

    struct Entity* statistics;
};

struct Object* NewObject(char* name, uint8_t posX, uint8_t posY){
    struct Object* result = calloc(1, sizeof(struct Object));

    result->posX = posX;
    result->posY = posY;
    result->name = name;
    result->statistics = NULL;
    // result-> pointer to spirites = 

    return result;
}

#endif
