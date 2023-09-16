CC = clang
OUT = build
CFLAGS = -Wall -Wextra
SRC = src/*.c

all:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)/main

test: all
	./build/main

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
