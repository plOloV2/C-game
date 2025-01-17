#include <stdlib.h>

struct Item
{
    uint8_t id;
    char* name;
    uint8_t type;
    uint8_t stat1;
    uint8_t stat2;
    uint8_t stat3;
    uint8_t stat4;

    // sprite 
};

enum item_types
{
    QUEST,
    ARMOR_HEAD,
    ARMOR_CHEST,
    ARMOR_HANDS,
    ARMOR_LEGS,
    BOOTS,
    RING,
    WEAPON_MELE,
    WEAPON_RANGE,
    ITEAM,
    CONSUMABLE
};


struct Item* CreatItem (uint8_t id);
