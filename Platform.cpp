#include "Platform.hpp"
#include "raylib.hpp"
#include "Chip8.hpp"
#include <stdint.h>

// Platform::Platform(){

// }



// renders the display for one frame
void Platform::RenderDisplay(int Chip8_width, int Chip8_height, int scale, uint32_t* video) 
{

    for (int y = 0; y < Chip8_height; y++) 
    {
        for (int x = 0; x < Chip8_width; x++) 
        {
            if (video[y * Chip8_width + x]) 
            {
                DrawRectangle(x * scale, y * scale, scale, scale, WHITE);
            }
        }
    }
}



void Platform::ProcessInput(uint8_t* keys)
{
    for (int i = 0; i < 16; i++) 
    {
        keys[i] = IsKeyDown(keyMap[i]) ? 1 : 0;
    }

}




    // Platform::Platform(const char* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
    // {
    //     // Initialize Raylib
    //     InitWindow(windowWidth, windowHeight, title);
    //     SetTargetFPS(60);

    //     // Create a texture
    //     texture = LoadRenderTexture(textureWidth, textureHeight);
    // }







    // Platform::~Platform()
    // {
    //     // Unload the texture and close window
    //     UnloadRenderTexture(texture);
    //     CloseWindow();
    // }







    // void Platform::Update(void const* buffer, int pitch)
    // {
    //     // Update texture with new buffer data
    //     UpdateTexture(texture.texture, buffer);

    //     // Begin drawing to the render texture
    //     BeginDrawing();
    //     ClearBackground(RAYWHITE);

    //     // Draw the texture to the screen
    //     Rectangle sourceRec = { 0, 0, (float)texture.texture.width, (float)texture.texture.height }; // Full texture
    //     Vector2 position = { 0, 0 };  // Position the texture at (0, 0)
    //     DrawTextureRec(texture.texture, sourceRec, position, WHITE);

    //     // End drawing to the screen
    //     EndDrawing();
    // }





    // bool Platform::ProcessInput(uint8_t* keys)
    // {
    //     bool quit = false;

    //     // Handle keyboard input
    //     if (WindowShouldClose())
    //     {
    //         quit = true;
    //     }

    //     if (IsKeyPressed(KEY_ESCAPE))
    //     {
    //         quit = true;
    //     }

    //     // Map key events to the `keys` array
    //     if (IsKeyPressed(KEY_X)) keys[0] = 1;
    //     if (IsKeyPressed(KEY_ONE)) keys[1] = 1;
    //     if (IsKeyPressed(KEY_TWO)) keys[2] = 1;
    //     if (IsKeyPressed(KEY_THREE)) keys[3] = 1;
    //     if (IsKeyPressed(KEY_Q)) keys[4] = 1;
    //     if (IsKeyPressed(KEY_W)) keys[5] = 1;
    //     if (IsKeyPressed(KEY_E)) keys[6] = 1;
    //     if (IsKeyPressed(KEY_A)) keys[7] = 1;
    //     if (IsKeyPressed(KEY_S)) keys[8] = 1;
    //     if (IsKeyPressed(KEY_D)) keys[9] = 1;
    //     if (IsKeyPressed(KEY_Z)) keys[0xA] = 1;
    //     if (IsKeyPressed(KEY_C)) keys[0xB] = 1;
    //     if (IsKeyPressed(KEY_FOUR)) keys[0xC] = 1;
    //     if (IsKeyPressed(KEY_R)) keys[0xD] = 1;
    //     if (IsKeyPressed(KEY_F)) keys[0xE] = 1;
    //     if (IsKeyPressed(KEY_V)) keys[0xF] = 1;

    //     if (IsKeyReleased(KEY_X)) keys[0] = 0;
    //     if (IsKeyReleased(KEY_ONE)) keys[1] = 0;
    //     if (IsKeyReleased(KEY_TWO)) keys[2] = 0;
    //     if (IsKeyReleased(KEY_THREE)) keys[3] = 0;
    //     if (IsKeyReleased(KEY_Q)) keys[4] = 0;
    //     if (IsKeyReleased(KEY_W)) keys[5] = 0;
    //     if (IsKeyReleased(KEY_E)) keys[6] = 0;
    //     if (IsKeyReleased(KEY_A)) keys[7] = 0;
    //     if (IsKeyReleased(KEY_S)) keys[8] = 0;
    //     if (IsKeyReleased(KEY_D)) keys[9] = 0;
    //     if (IsKeyReleased(KEY_Z)) keys[0xA] = 0;
    //     if (IsKeyReleased(KEY_C)) keys[0xB] = 0;
    //     if (IsKeyReleased(KEY_FOUR)) keys[0xC] = 0;
    //     if (IsKeyReleased(KEY_R)) keys[0xD] = 0;
    //     if (IsKeyReleased(KEY_F)) keys[0xE] = 0;
    //     if (IsKeyReleased(KEY_V)) keys[0xF] = 0;

    //     return quit;
    // }
