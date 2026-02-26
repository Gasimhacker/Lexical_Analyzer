# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

# Executable name
NAME = lexer

# Source files
SRC = $(wildcard src/*.c)

# Header files
HEADER = lexer.h

# Default target
all: $(NAME)

# Create executable
$(NAME): $(SRC)
	@echo ""
	@echo "-------------------------------------------------------------------"
	@echo "Creating lexer..."
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
	@echo "Lexer created"
	@echo "-------------------------------------------------------------------"
	@echo ""

# Run the lexer with a target file or directory
# Usage: make run TARGET=<file_or_directory>
run: $(NAME)
ifndef TARGET
	@echo "Usage: make run TARGET=<file_or_directory>"
	@echo "Example: make run TARGET=tests/simple_declaration"
	@echo "Example: make run TARGET=tests"
	@echo ""
	@echo "Running the lexer without arguments"
	./$(NAME)
	@echo ""
else
	./$(NAME) $(TARGET)
endif

# Delete executable
clean:
	rm -f $(NAME)

# Rebuild from scratch
re: clean all


.PHONY: all clean re run
