#include "Chip8.hpp"
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <random>
#include <iostream>

const unsigned int START_ADDRESS = 0x200; // everything before this is reserved for interpreter
const unsigned int FONT_START_ADDRESS = 0x50; // in interpreter area of memory
const unsigned int FONT_SIZE = 80; // 16 chars, 5 bytes each

// array of character sprites
uint8_t fontset[FONT_SIZE] =           
{
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F

};


Chip8::Chip8() 
    : randGen(std::chrono::system_clock::now().time_since_epoch().count())
{
    pc = START_ADDRESS;


    // load character sprites into memory (stored in interpreter area)
    for (unsigned int i = 0; i < FONT_SIZE; i++)
    {
        memory[FONT_START_ADDRESS + i] = fontset[i];
    }

    // initalize random number generator (call with randByte(randGen))
    randByte = std::uniform_int_distribution<uint8_t>(0, 255u); // will give back a byte between 0 and 255

    
}

void Chip8::decode(uint16_t opcode)
{
    if (opcode == 0x00E0) 
    {
        OP_00E0();
    }

    else if (opcode == 0x00EE)
    {
        OP_00EE();
    }

    else if ((opcode & 0xF000) == 0x1000)
    {
        OP_1nnn();
    }

    else if ((opcode & 0xF000) == 0x2000)
    {
        OP_2nnn();
    }

    else if ((opcode & 0xF000) == 0x3000)
    {
        OP_3xkk();
    }

    else if ((opcode & 0xF000) == 0x4000)
    {
        OP_4xkk();
    }

    else if ((opcode & 0xF000) == 0x5000)
    {
        OP_5xy0();
    }

    else if ((opcode & 0xF000) == 0x6000)
    {
        OP_6xkk();
    }

    else if ((opcode & 0xF000) == 0x7000)
    {
        OP_7xkk();
    }

    else if ((opcode & 0xF00F) == 0x8000)
    {
        OP_8xy0();
    }

    else if ((opcode & 0xF00F) == 0x8001)
    {
        OP_8xy1();
    }

    else if ((opcode & 0xF00F) == 0x8002)
    {
        OP_8xy2();
    }

    else if ((opcode & 0xF00F) == 0x8003)
    {
        OP_8xy3();
    }

    else if ((opcode & 0xF00F) == 0x8004)
    {
        OP_8xy4();
    }

    else if ((opcode & 0xF00F) == 0x8005)
    {
        OP_8xy5();
    }

    else if ((opcode & 0xF00F) == 0x8006)
    {
        OP_8xy6();
    }

    else if ((opcode & 0xF00F) == 0x8007)
    {
        OP_8xy7();
    }

    else if ((opcode & 0xF00F) == 0x800E)
    {
        OP_8xyE();
    }

    else if ((opcode & 0xF00F) == 0x9000)
    {
        OP_9xy0();
    }

    else if ((opcode & 0xF000) == 0xA000)
    {
        OP_Annn();
    }

    else if ((opcode & 0xF000) == 0xB000)
    {
        OP_Bnnn();
    }

    else if ((opcode & 0xF000) == 0xC000)
    {
        OP_Cxkk();
    }

    else if ((opcode & 0xF000) == 0xD000)
    {
        OP_Dxyn();
    }

    else if ((opcode & 0xF0FF) == 0xE09E)
    {
        OP_Ex9E();
    }

    else if ((opcode & 0xF0FF) == 0xE0A1)
    {
        OP_ExA1();
    }

    else if ((opcode & 0xF0FF) == 0xF007)
    {
        OP_Fx07();
    }

    else if ((opcode & 0xF0FF) == 0xF00A)
    {
        OP_Fx0A();
    }

    else if ((opcode & 0xF0FF) == 0xF015)
    {
        OP_Fx15();
    }

    else if ((opcode & 0xF0FF) == 0xF018)
    {
        OP_Fx18();
    }

    else if ((opcode & 0xF0FF) == 0xF01E)
    {
        OP_Fx1E();
    }

    else if ((opcode & 0xF0FF) == 0xF029)
    {
        OP_Fx29();
    }

    else if ((opcode & 0xF0FF) == 0xF033)
    {
        OP_Fx33();
    }

    else if ((opcode & 0xF0FF) == 0xF055)
    {
        OP_Fx55();
    }

    else if ((opcode & 0xF0FF) == 0xF065)
    {
        OP_Fx65();
    }
}

void Chip8::Cycle()
{
    // fetch
    opcode = (memory[pc] << 8u) | memory[pc+1]; // opcode takes up two indices in memory b/c its 16 bits, and memory is 8 bits each index

    pc += 2; // increment pc

    decode(opcode);

    if (delayTimer > 0)
    {
        delayTimer--;
    }

    if (soundTimer > 0)
    {
        soundTimer--;
    }

}





void Chip8::LoadROM(const char* filename)
{
    // open as binary and move pointer to end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open())
    {
        // obtain size and allocate buffer
        std::streampos size = file.tellg(); // gives byte offset from start of file to pointer (which is currently at end of file)
        char* buffer = new char[size]; // use that size to allocate space

        // set pointer to start of file and fill out buffer
        file.seekg(0, std::ios::beg); // (offset, reference flag)
        file.read(buffer, size); // read into "buffer" for "size" number of bytes
        file.close();

        // load ROM contents into Chip8 memory from starting address
        for (int i = 0; i < size; i++)
        {
            memory[START_ADDRESS + i] = buffer[i];
        }

        // free buffer
        delete[] buffer;
    }
}

void Chip8::OP_NULL(){}
// clears the video display
void Chip8::OP_00E0()
{
    // fill video array block with 0s
    memset(video, 0, sizeof(video)); 
}

// return from a subroutine
void Chip8::OP_00EE()
{
    sp--; // subtract one from stack pointer to pop current address from stack
    pc = stack[sp]; // now sp points at the return address, which pc will use

}

// jump to location nnn
void Chip8::OP_1nnn()
{
    uint16_t address = opcode & 0x0FFFu; // assign the lower 12 bits (nnn) to address
    pc = address; // set pc to address
}

// call subroutine at nnn
void Chip8::OP_2nnn()
{
    uint16_t address = opcode & 0x0FFFu;
    // push pc to stack
    stack[sp] = pc;
    sp++;

    pc = address; // assign the lower 12 bits (nnn) to pc
}

// skip next instruction if Vx = kk
void Chip8::OP_3xkk()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // mask bits 11-8, then shift right 8 bits so its the least significant byte
    uint16_t kk = opcode & 0x00FFu;

    if (registers[Vx] == kk)
    {
        pc += 2;
    }
}

// Skip next instruction if Vx != kk
void Chip8::OP_4xkk()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // mask bits 11-8, then shift right 8 bits so its the least significant byte
    uint16_t kk = opcode & 0x00FFu;

    if (registers[Vx] != kk)
    {
        pc += 2;
    }
}

// Skip next instruction if Vx = Vy
void Chip8::OP_5xy0()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    if (registers[Vx] == registers[Vy])
    {
        pc += 2; // increment by 1 address b/c in cycle it increments another by default
    }
}

// Set Vx = kk
void Chip8::OP_6xkk()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    uint16_t kk = opcode & 0x00FFu;

    registers[Vx] = kk;
}

// Set Vx = Vx + kk
void Chip8::OP_7xkk()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    uint16_t kk = opcode & 0x00FFu;

    registers[Vx] += kk; // adds kk to value of register Vx, then store it back into register Vx
}

// Set Vx = Vy
void Chip8::OP_8xy0()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    registers[Vx] = registers[Vy];
}

// Set Vx = Vx OR Vy
void Chip8::OP_8xy1()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    registers[Vx] = registers[Vx] | registers[Vy];
}

// Set Vx = Vx AND Vy
void Chip8::OP_8xy2()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    registers[Vx] = registers[Vx] & registers[Vy];
}

// Set Vx = Vx XOR Vy
void Chip8::OP_8xy3()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    registers[Vx] = registers[Vx] ^ registers[Vy];
}

// Set Vx = Vx + Vy, set VF = carry
void Chip8::OP_8xy4()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte

    uint8_t sum = registers[Vx] + registers[Vy];

    // there is overflow
    if (sum > 255u)
    {
        registers[0xF] = 1;
    } 
    
    // if no overflow
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = sum & 0xFF; // lowest 8 bits of result are kept

}

// Set Vx = Vx - Vy, set VF = NOT borrow
void Chip8::OP_8xy5()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte


    if (registers[Vx] > registers[Vy])
    {
        registers[0xF] = 1;
    }

    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] -= registers[Vy];
}

// Set Vx = Vx SHR 1
void Chip8::OP_8xy6()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte

    if ((registers[Vx] & 0x1) == 1) // if lsb of value of Vx is 1
    {
        registers[0xF] = 1;
    }

    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = registers[Vx] >> 1; // divide by 2
}

// Set Vx = Vy - Vx, set VF = NOT borrow
void Chip8::OP_8xy7()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte


    if (registers[Vy] > registers[Vx])
    {
        registers[0xF] = 1;
    }

    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = registers[Vy] - registers[Vx];
}

// Set Vx = Vx SHL 1
void Chip8::OP_8xyE()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte

    if ((registers[Vx] & 0x8000) == 1) // if lsb of value of Vx is 1
    {
        registers[0xF] = 1;
    }

    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = registers[Vx] << 1; // multiply by 2
}

// Skip next instruction if Vx != Vy
void Chip8::OP_9xy0()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte


    if (registers[Vy] != registers[Vx])
    {
        pc += 2;
    }
}

// Set I = nnn
void Chip8::OP_Annn()
{
    uint16_t address = opcode & 0x0FFFu;

    index = address;

}

// Jump to location nnn + V0
void Chip8::OP_Bnnn()
{
    uint16_t nnn = opcode & 0x0FFFu;

    pc = nnn + registers[0x0];
}

// Set Vx = random byte AND kk
void Chip8::OP_Cxkk()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t kk = opcode & 0x00FFu;

    registers[Vx] = randByte(randGen) & kk;
}

// Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision
void Chip8::OP_Dxyn()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint16_t Vy = (opcode & 0x00F0u) >> 4u; // upper 4 bits of the low byte
    uint8_t height = opcode & 0x000Fu;

    // starting values
    uint8_t xPos = registers[Vx] % VIDEO_WIDTH; // shrink down the sprite
    uint8_t yPos = registers[Vy] % VIDEO_HEIGHT;

    registers[0xF] = 0; // set VF = 0 for no collision

    for (unsigned int row = 0; row < height; row++)
    {
        uint16_t spriteByte = memory[index + row];

        for (unsigned int col = 0; col < 8; col++) // sprite guaranteed to be 8 pixels/bits wide 
        {
            uint8_t spritePixel = (spriteByte & (0x80u >> col)); // check if specific pixel is on or off (iterate through the columsn in spriteByte)
            uint32_t* screenPixel = &video[(yPos + row) * VIDEO_WIDTH + (xPos + col)]; // find the index of the pixel

            if (spritePixel != 0) // if pixel is on
            {
                // if screen pixel is on, raise collision flag
                if (*screenPixel == 0xFFFFFFFF)
                {
                    registers[0xF] = 1;
                }

                *screenPixel = *screenPixel ^ 0xFFFFFFFF;
            }
        }
    }
}

// Skip next instruction if key with the value of Vx is pressed
void Chip8::OP_Ex9E()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint8_t key = registers[Vx];
    if (keypad[key]) // if key has been pressed
    {
        pc += 2;
    }
}

// Skip next instruction if key with the value of Vx is not pressed
void Chip8::OP_ExA1()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    uint8_t key = registers[Vx];
    if (keypad[key] == 0) // if key has not been pressed
    {
        pc += 2;
    }
}

// Set Vx = delay timer value
void Chip8::OP_Fx07()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte
    registers[Vx] = delayTimer;
}

// Wait for a key press, store the value of the key in Vx
void Chip8::OP_Fx0A()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte

    if (keypad[0]) 
    {
        registers[Vx] = 0;
    }

    else if (keypad[1])
    {
        registers[Vx] = 1;
    }

    else if (keypad[2])
    {
        registers[Vx] = 2;
    }

    else if (keypad[3])
    {
        registers[Vx] = 3;
    }

    else if (keypad[4])
    {
        registers[Vx] = 4;
    }

    else if (keypad[5])
    {
        registers[Vx] = 5;
    }

    else if (keypad[6])
    {
        registers[Vx] = 6;
    }

    else if (keypad[7])
    {
        registers[Vx] = 7;
    }

    else if (keypad[8])
    {
        registers[Vx] = 8;
    }

    else if (keypad[9])
    {
        registers[Vx] = 9;
    }

    else if (keypad[10])
    {
        registers[Vx] = 10;
    }

    else if (keypad[11])
    {
        registers[Vx] = 11;
    }
    else if (keypad[12])
    {
        registers[Vx] = 12;
    }
    else if (keypad[13])
    {
        registers[Vx] = 13;
    }
    else if (keypad[14])
    {
        registers[Vx] = 14;
    }
    else if (keypad[15])
    {
        registers[Vx] = 15;
    }

    else
    {
        pc -= 2; // decrement to repeat this instruction until a key is pressed
    }


}

// DT is set equal to the value of Vx
void Chip8::OP_Fx15()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte

    delayTimer = registers[Vx];
}

// ST is set equal to the value of Vx
void Chip8::OP_Fx18()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u; // lower 4 bits of the high byte

    soundTimer = registers[Vx];
}


// Set I = I + Vx
void Chip8::OP_Fx1E()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;

    index += registers[Vx];
}

// Set I = location of sprite for digit Vx
void Chip8::OP_Fx29()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t digit = registers[Vx];

    index = FONT_START_ADDRESS + (5 * digit); // font characters are 5 bytes each; add to FONT_START_ADDRESS as offset to get their address
}

// Store BCD representation of Vx in memory locations I, I+1, and I+2
void Chip8::OP_Fx33()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t decimalVal = registers[Vx];

    // for 100s place
    memory[index] = decimalVal / 100;
    decimalVal = decimalVal - memory[index] * 100;

    // for 10s place
    memory[index + 1] = decimalVal / 10;
    decimalVal = decimalVal - memory[index] * 10;

    // for 1s place
    memory[index + 2] = decimalVal;
}

// Store registers V0 through Vx in memory starting at location I
void Chip8::OP_Fx55()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    for (int i = 0; i <= Vx; i++)
    {
        memory[index + i] = registers[i];
    }
}

// Read registers V0 through Vx from memory starting at location I
void Chip8::OP_Fx65()
{
    uint16_t Vx = (opcode & 0x0F00u) >> 8u;
    for (int i = 0; i <= Vx; i++)
    {
        registers[i] = memory[index + i];
    }
}