#include <SDL3/SDL.h>
#include <stdlib.h>

struct Inputs
{
    uint32_t keysPressed;
    uint8_t quit;
    float mouseX;
    float mouseY;
};

enum KeyPress
{
    KEY_PRESS_ESCAPE,
    KEY_PRESS_SPACE,
    KEY_PRESS_ENTER,
    KEY_PRESS_SHIFT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_ACTION1,
    KEY_PRESS_ACTION2,
    MOUSE_KEY_PRESS_LEFT,
    MOUSE_LEFT_KEY_FREE,
    MOUSE_KEY_PRESS_RIGHT,
    MOUSE_RIGHT_KEY_FREE
};
