CC = clang
OUT = build
CFLAGS = -Wall -Wextra -g
SRCS = $(wildcard src/*.c src/**/*.c)
DEFINES = -DLEVEL=5
OBJ = $(SRC:.c=.o)

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(DEFINES) -c $^ -o $@

all: $(OBJ)
	mkdir -p $(OUT)
	$(CC) $^ -o $(OUT)/out

test: all
	echo $(shell pwd)
	./build/out

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
