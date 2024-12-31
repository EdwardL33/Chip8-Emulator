#include <cstdint>
#include <random>

const unsigned int REGISTER_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int NUMBER_OF_KEYS = 16;
const unsigned int VIDEO_WIDTH = 64;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int STACK_LEVELS = 16;
/**
 * class containing variables and functions necessary to run a Chip 8 emulator
 */
class Chip8
{
public: 
    /**
     * constructor that loads character spirtes into memory
     */
    Chip8();

    uint8_t registers[REGISTER_COUNT]{};
    uint8_t memory[MEMORY_SIZE]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[STACK_LEVELS]{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[NUMBER_OF_KEYS]{};
    uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{}; // width by height
    uint16_t opcode;

    /**
     * reads instructions from a ROM and loads them into memory starting from 0x200
     */
    void LoadROM(const char* filename);

    /**
     * decodes the opcode
     */
    void decode(uint16_t opcode);
    
    /**
     * one cycle involves fetching next instruct's opcode, decoding that instruct, and executing it
     */
    void Cycle();
    
    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;

    // do nothing
    void OP_NULL();

    // CLS
    void OP_00E0();

    // RET
    void OP_00EE();
    
    // JP addr
    void OP_1nnn();

    // CALL addr
    void OP_2nnn();

    // SE Vx, byte
    void OP_3xkk();

    // SNE Vx, byte
    void OP_4xkk();

    // SE Vx, Vy
    void OP_5xy0();

    // LD Vx, byte
    void OP_6xkk();

    // ADD Vx, byte
    void OP_7xkk();

    // LD Vx, byte
    void OP_8xy0();

    // OR Vx, Vy
    void OP_8xy1();

    // AND Vx, Vy
    void OP_8xy2();

    // XOR Vx, Vy
    void OP_8xy3();

    // ADD Vx, Vy
    void OP_8xy4();

    // SUB Vx, Vy
    void OP_8xy5();

    // SHR Vx {, Vy}
    void OP_8xy6();

    // SUBN Vx, Vy
    void OP_8xy7();

    // SHL Vx {, Vy}
    void OP_8xyE();

    // SNE Vx, Vy
    void OP_9xy0();

    // LD I, addr
    void OP_Annn();

    // JP V0, addr
    void OP_Bnnn();

    // RND Vx, byte
    void OP_Cxkk();

    // DRW Vx, Vy, nibble
    void OP_Dxyn();

    //SKP Vx
    void OP_Ex9E();

    // SKNP Vx
    void OP_ExA1();

    // LD Vx, DT
    void OP_Fx07();

    // LD Vx, K
    void OP_Fx0A();

    // Set delay timer = Vx
    void OP_Fx15();

    // LD ST, Vx
    void OP_Fx18();

    // ADD I, Vx
    void OP_Fx1E();

    // LD F, Vx
    void OP_Fx29();

    // LD B, Vx
    void OP_Fx33();

    // LD [I], Vx
    void OP_Fx55();

    // LD Vx, [I]
    void OP_Fx65();
};  