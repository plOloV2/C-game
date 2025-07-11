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

    struct Item** wearing;
};

enum BUFFS
{
    DEF_UP,             //UP -> stat x2
    DEF_DOWN,           //DOWN -> stat /2
    SDEF_UP,
    SDEF_DOWN,
    ATK_UP,
    ATK_DOWN,
    SATK_UP,
    SATK_DOWN,
    SPEED_UP,
    SPEED_DOWN,
    POISON,             //takes 1/8 health every turn
    STUN,               //can't move
    INCELS,             //pur, stach, karol
    WT,                 //pur, tymus, karol, viktor
    ENSLAVED,           //tymus, wiktor, wojtek
    MATH_MANS,          //pur, kacpii, wiktor
};


struct Entity* CreatEntity(uint8_t Lvl, uint16_t max_HP, uint8_t Speed, uint8_t Attack, uint8_t Deffence, uint8_t SAttack, uint8_t SDeffence){

    struct Entity* result = calloc(1, sizeof(struct Entity));

    result->Level = Lvl;
    result->max_HP = max_HP;
    result->Speed = Speed;
    result->Attack = Attack;
    result->Deffence = Deffence;
    result->SAttack = SAttack;
    result->SDeffence = SDeffence;
    result->wearing = NULL;

    return result;
}
