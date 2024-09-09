CROSS_COMPILE ?=
# Compiler (Uses cross compiler if CROSS_COMPILE is set)
CC = $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g

# Source files
SRC = writer.c

# Executable name
TARGET = writer

# Object files
OBJ = $(SRC:.c=.o)

# Compile the source files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean

# Clean the object files
clean:
	rm -f $(OBJ) $(TARGET)