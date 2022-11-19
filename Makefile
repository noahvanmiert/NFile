EXEC = nfile
SRC = src
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -g -Wall -Wextra -Werror -pedantic
COMPILER = gcc
BINDIR = bin

$(BINDIR)/$(EXEC): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(FLAGS) -o $(BINDIR)/$(EXEC)

clean:
	rm bin/nfile src/*.o
