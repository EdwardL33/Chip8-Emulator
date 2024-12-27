#include "Chip8.hpp"
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <random>

const unsigned int START_ADDRESS = 0x200; // everything before this is reserved for interpreter

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