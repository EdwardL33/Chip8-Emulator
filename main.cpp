#include "Chip8.hpp"
#include "Platform.hpp"
#include <chrono>
#include <iostream>
#include "include/raylib.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
		std::exit(EXIT_FAILURE);
	}

	int videoScale = std::stoi(argv[1]);
	int cycleDelay = std::stoi(argv[2]);
	char const* romFilename = argv[3];

    // InitWindow(VIDEO_WIDTH*videoScale, VIDEO_HEIGHT*videoScale, "title");
    // SetTargetFPS(60);

    // Platform platform;
    Platform platform("CHIP-8 Emulator", VIDEO_WIDTH * videoScale, VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);

    Chip8 chip8;
    chip8.LoadROM(romFilename);

    int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;
    auto lastCycleTime = std::chrono::high_resolution_clock::now();


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        platform.ProcessInput(chip8.keypad);

        auto currentTime = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();
        

		if (dt > cycleDelay)
		{   
			lastCycleTime = currentTime;

			chip8.Cycle();
            // BeginDrawing();
			// platform.RenderDisplay(VIDEO_WIDTH, VIDEO_HEIGHT, videoScale, chip8.video);
            // EndDrawing();
            platform.Update(chip8.video, videoPitch, VIDEO_HEIGHT*videoScale, VIDEO_WIDTH*videoScale);
            
		}


    }

    std::cout << "worked?\n";

    return 0;

}


