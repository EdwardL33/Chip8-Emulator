# Which compiler to use
CC = g++

# Final executable
TARGET = Chip8
# Files to be compiled
OBJ = Chip8.cpp main.cpp

# Default Make recipe
default: $(TARGET)

$(TARGET):
	$(CC) $(OBJ) -o $(TARGET)

# Clean recipe: removes all build artifacts
clean:
	$(RM) $(TARGET)