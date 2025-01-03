#include "include/raylib.hpp"

class Platform
{

    // 1 2 3 4      ->   1 2 3 4
    // Q W E R      ->   4 5 6 C
    // A S D F      ->   7 8 9 E
    // Z X C V      ->   A 0 B F


 
    int keyMap[16] = {      // maps Chip8 keys to keyboard keys
    KEY_X,    // 0
    KEY_ONE,  // 1
    KEY_TWO,  // 2
    KEY_THREE,// 3
    KEY_Q,    // 4
    KEY_W,    // 5
    KEY_E,    // 6
    KEY_A,    // 7
    KEY_S,    // 8
    KEY_D,    // 9
    KEY_Z,    // A
    KEY_C,    // B
    KEY_FOUR, // C
    KEY_R,    // D
    KEY_F,    // E
    KEY_V     // F
    };

    // renders a pixel/rectangle across the entire display
    void RenderDisplay();

    // handles keyboard input with the keys array
    void ProcessInput(uint8_t* keys);
};