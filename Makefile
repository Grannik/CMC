CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = complex_modules_clock
SOURCES = complex_modules_clock.c $(wildcard module_*.c) common.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
