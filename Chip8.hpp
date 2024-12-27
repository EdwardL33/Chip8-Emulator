#include <cstdint>
#include <random>

const unsigned int REGISTER_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int NUMBER_OF_KEYS = 16;
const unsigned int VIDEO_WIDTH = 64;
const unsigned int VIDEO_HEIGHT = 32;
/**
 * class containing variables and functions necessary to run a Chip 8 emulator
 */
class Chip8
{
public:
    Chip8(); // default constructor for class

    uint8_t registers[REGISTER_COUNT]{};
    uint8_t memory[MEMORY_SIZE]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[NUMBER_OF_KEYS]{};
    uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{}; // width by height
    uint16_t opcode;

    void LoadROM(const char* filename);



};