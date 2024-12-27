# Which compiler to use
CC = g++
# Compiler flags
CFLAGS = -I. -O0 -g -Werror=vla
# Final executable
TARGET = Chip8
# File to be compiled
OBJTEST = Chip8.cpp

# Default Make recipe
default: $(TARGET)

$(TARGET):
	$(CC) $(OBJTEST) -o $(TARGET)

# Clean recipe: removes all build artifacts
clean:
	$(RM) $(TARGET)