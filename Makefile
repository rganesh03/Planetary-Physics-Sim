CC = gcc
CFLAGS = -Wall -I/mingw64/include/SDL2
LDFLAGS = -L/mingw64/lib -lmingw32 -lSDL2main -lSDL2
TARGET = simulation
SRCS = main.c physics.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)