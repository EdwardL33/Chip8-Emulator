# # Which compiler to use
# CC = g++

# # Final executable
# TARGET = Chip8
# # Files to be compiled
# OBJ = Chip8.cpp main.cpp

# # Default Make recipe
# default: $(TARGET)

# $(TARGET):
# 	$(CC) $(OBJ) -o $(TARGET)

# # Clean recipe: removes all build artifacts
# clean:
# 	$(RM) $(TARGET)


# all:
# 	g++ -Isrc/Include -Lsrc/lib main.cpp Chip8.cpp -o Chip8 -lmingw32 -lSDL2main -lSDL2

CXX = g++ #i686-w64-mingw32-g++
CXXFLAGS = -I src/include
LDFLAGS = -L src/lib -lSDL2main -lSDL2
SOURCES = main.cpp Chip8.cpp
TARGET = Chip8

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)
	
clean:
	$(RM) Chip8