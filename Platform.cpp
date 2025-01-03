#include "Platform.hpp"
#include "raylib.hpp"
#include "Chip8.hpp"
#include <stdint.h>

// Platform::Platform(){

// }



// renders the display for one frame
// void Platform::RenderDisplay(int Chip8_width, int Chip8_height, int scale, uint32_t* video) 
// {

//     for (int y = 0; y < Chip8_height; y++) 
//     {
//         for (int x = 0; x < Chip8_width; x++) 
//         {
//             if (video[y * Chip8_width + x]) 
//             {
//                 DrawRectangle(x * scale, y * scale, scale, scale, WHITE);
//             }
//         }
//     }
// }



// void Platform::ProcessInput(uint8_t* keys)
// {
//     for (int i = 0; i < 16; i++) 
//     {
//         keys[i] = IsKeyDown(keyMap[i]) ? 1 : 0;
//     }

// }




    Platform::Platform(const char* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
    {
        // Initialize Raylib
        InitWindow(windowWidth, windowHeight, title);
        SetTargetFPS(60);

        // Create a texture
        texture = LoadRenderTexture(textureWidth, textureHeight);
    }







    Platform::~Platform()
    {
        // Unload the texture and close window
        UnloadRenderTexture(texture);
        CloseWindow();
    }







    void Platform::Update(void const* buffer, int pitch, float winHeight, float winWidth)
    {
        // Update texture with new buffer data
        
        UpdateTexture(texture.texture, buffer);

        // Begin drawing to the render texture
        BeginDrawing();
        ClearBackground(BLANK);

        // // Draw the texture to the screen
        // Rectangle sourceRec = { 0, 0, (float)texture.texture.width, (float)texture.texture.height }; // Full texture
        // Vector2 position = { 0, 0 };  // Position the texture at (0, 0)
        // DrawTextureRec(texture.texture, sourceRec, position, WHITE);

        DrawTexturePro ( texture.texture
                , (Rectangle) { 0, 0, (float)texture.texture.width, (float)texture.texture.height }
                , (Rectangle) { 0, 0, winWidth, winHeight }
                , ( Vector2 )   { 0, 0 }
                , 0
                , WHITE );

        // End drawing to the screen
        EndDrawing();
    }





    bool Platform::ProcessInput(uint8_t* keys)
    {
        bool quit = false;

        // Handle keyboard input
        if (WindowShouldClose())
        {
            quit = true;
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
            quit = true;
        }

        // Map key events to the `keys` array
        // if (IsKeyPressed(KEY_X)) keys[0] = 1;
        // if (IsKeyPressed(KEY_ONE)) keys[1] = 1;
        // if (IsKeyPressed(KEY_TWO)) keys[2] = 1;
        // if (IsKeyPressed(KEY_THREE)) keys[3] = 1;
        // if (IsKeyPressed(KEY_Q)) keys[4] = 1;
        // if (IsKeyPressed(KEY_W)) keys[5] = 1;
        // if (IsKeyPressed(KEY_E)) keys[6] = 1;
        // if (IsKeyPressed(KEY_A)) keys[7] = 1;
        // if (IsKeyPressed(KEY_S)) keys[8] = 1;
        // if (IsKeyPressed(KEY_D)) keys[9] = 1;
        // if (IsKeyPressed(KEY_Z)) keys[0xA] = 1;
        // if (IsKeyPressed(KEY_C)) keys[0xB] = 1;
        // if (IsKeyPressed(KEY_FOUR)) keys[0xC] = 1;
        // if (IsKeyPressed(KEY_R)) keys[0xD] = 1;
        // if (IsKeyPressed(KEY_F)) keys[0xE] = 1;
        // if (IsKeyPressed(KEY_V)) keys[0xF] = 1;

        // if (IsKeyReleased(KEY_X)) keys[0] = 0;
        // if (IsKeyReleased(KEY_ONE)) keys[1] = 0;
        // if (IsKeyReleased(KEY_TWO)) keys[2] = 0;
        // if (IsKeyReleased(KEY_THREE)) keys[3] = 0;
        // if (IsKeyReleased(KEY_Q)) keys[4] = 0;
        // if (IsKeyReleased(KEY_W)) keys[5] = 0;
        // if (IsKeyReleased(KEY_E)) keys[6] = 0;
        // if (IsKeyReleased(KEY_A)) keys[7] = 0;
        // if (IsKeyReleased(KEY_S)) keys[8] = 0;
        // if (IsKeyReleased(KEY_D)) keys[9] = 0;
        // if (IsKeyReleased(KEY_Z)) keys[0xA] = 0;
        // if (IsKeyReleased(KEY_C)) keys[0xB] = 0;
        // if (IsKeyReleased(KEY_FOUR)) keys[0xC] = 0;
        // if (IsKeyReleased(KEY_R)) keys[0xD] = 0;
        // if (IsKeyReleased(KEY_F)) keys[0xE] = 0;
        // if (IsKeyReleased(KEY_V)) keys[0xF] = 0;

        if (IsKeyPressed(KEY_X)) {
            keys[0] = 1;
            printf("x pressed\n");
        }
        if (IsKeyPressed(KEY_ONE)) {
            keys[1] = 1;
            printf("1 pressed\n");
        }
        if (IsKeyPressed(KEY_TWO)) {
            keys[2] = 1;
            printf("2 pressed\n");
        }
        if (IsKeyPressed(KEY_THREE)) {
            keys[3] = 1;
            printf("3 pressed\n");
        }
        if (IsKeyPressed(KEY_Q)) {
            keys[4] = 1;
            printf("Q pressed\n");
        }
        if (IsKeyPressed(KEY_W)) {
            keys[5] = 1;
            printf("W pressed\n");
        }
        if (IsKeyPressed(KEY_E)) {
            keys[6] = 1;
            printf("E pressed\n");
        }
        if (IsKeyPressed(KEY_A)) {
            keys[7] = 1;
            printf("A pressed\n");
        }
        if (IsKeyPressed(KEY_S)) {
            keys[8] = 1;
            printf("S pressed\n");
        }
        if (IsKeyPressed(KEY_D)) {
            keys[9] = 1;
            printf("D pressed\n");
        }
        if (IsKeyPressed(KEY_Z)) {
            keys[0xA] = 1;
            printf("Z pressed\n");
        }
        if (IsKeyPressed(KEY_C)) {
            keys[0xB] = 1;
            printf("C pressed\n");
        }
        if (IsKeyPressed(KEY_FOUR)) {
            keys[0xC] = 1;
            printf("4 pressed\n");
        }
        if (IsKeyPressed(KEY_R)) {
            keys[0xD] = 1;
            printf("R pressed\n");
        }
        if (IsKeyPressed(KEY_F)) {
            keys[0xE] = 1;
            printf("F pressed\n");
        }
        if (IsKeyPressed(KEY_V)) {
            keys[0xF] = 1;
            printf("V pressed\n");
        }

        if (IsKeyReleased(KEY_X)) {
            keys[0] = 0;
            printf("x released\n");
        }
        if (IsKeyReleased(KEY_ONE)) {
            keys[1] = 0;
            printf("1 released\n");
        }
        if (IsKeyReleased(KEY_TWO)) {
            keys[2] = 0;
            printf("2 released\n");
        }
        if (IsKeyReleased(KEY_THREE)) {
            keys[3] = 0;
            printf("3 released\n");
        }
        if (IsKeyReleased(KEY_Q)) {
            keys[4] = 0;
            printf("Q released\n");
        }
        if (IsKeyReleased(KEY_W)) {
            keys[5] = 0;
            printf("W released\n");
        }
        if (IsKeyReleased(KEY_E)) {
            keys[6] = 0;
            printf("E released\n");
        }
        if (IsKeyReleased(KEY_A)) {
            keys[7] = 0;
            printf("A released\n");
        }
        if (IsKeyReleased(KEY_S)) {
            keys[8] = 0;
            printf("S released\n");
        }
        if (IsKeyReleased(KEY_D)) {
            keys[9] = 0;
            printf("D released\n");
        }
        if (IsKeyReleased(KEY_Z)) {
            keys[0xA] = 0;
            printf("Z released\n");
        }
        if (IsKeyReleased(KEY_C)) {
            keys[0xB] = 0;
            printf("C released\n");
        }
        if (IsKeyReleased(KEY_FOUR)) {
            keys[0xC] = 0;
            printf("4 released\n");
        }
        if (IsKeyReleased(KEY_R)) {
            keys[0xD] = 0;
            printf("R released\n");
        }
        if (IsKeyReleased(KEY_F)) {
            keys[0xE] = 0;
            printf("F released\n");
        }
        if (IsKeyReleased(KEY_V)) {
            keys[0xF] = 0;
            printf("V released\n");
        }

        return quit;
    }
