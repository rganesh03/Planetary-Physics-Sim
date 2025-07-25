# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -I.
LDFLAGS = -lSDL2

# Source files
SRCS = main.c input.c physics.c renderer.c
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = orbit_sim

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Compile each .c file into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)