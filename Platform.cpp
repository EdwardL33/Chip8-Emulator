#include "Platform.hpp"
#include "raylib.hpp"
#include "Chip8.hpp"


// renders the display for one frame
void Platform::RenderDisplay() 
{
    int Chip8_width = 64;
    int Chip8_height = 32;
    int scale = 10;  // Scale for rendering the 64x32 display on modern computer


    Chip8 chip8;

    for (int y = 0; y < Chip8_height; y++) 
    {
        for (int x = 0; x < Chip8_width; x++) 
        {
            if (chip8.video[y * Chip8_width + x]) 
            {
                DrawRectangle(x * scale, y * scale, scale, scale, WHITE);
            }
        }
    }
}



void Platform::ProcessInput(uint8_t* keys)
{
    Chip8 chip8;
    for (int i = 0; i < 16; i++) {
        keys[i] = IsKeyDown(keyMap[i]) ? 1 : 0;
    }

}