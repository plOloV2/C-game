#include <stdlib.h>

struct Entity
{
    uint8_t Level;
    uint16_t max_HP;
    uint16_t HP;
    uint8_t Speed;
    uint8_t Attack;
    uint8_t Deffence;
    uint8_t SAttack;
    uint8_t SDeffence;
    uint32_t Buffs;

    struct item* wearing;
    struct item* inventory;
};

struct Entity* CreatEntity(uint8_t Lvl, uint16_t max_HP, uint8_t Speed, uint8_t Attack, uint8_t Deffence, uint8_t SAttack, uint8_t SDeffence){
    
}