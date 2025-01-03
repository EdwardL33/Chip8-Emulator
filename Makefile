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

CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -I include/
LDFLAGS = -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
SOURCES = main.cpp Chip8.cpp Platform.cpp
TARGET = Chip8.exe

all:
	$(CXX) $(SOURCES) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS) -Wall -Wno-missing-braces
	
clean:
	$(RM) Chip8.exe