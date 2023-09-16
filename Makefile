CC = clang
OUT = build
CFLAGS = -Wall -Wextra
SRCS = $(wildcard src/*.c src/**/*.c)

all:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT)/main

test: all
	./build/main

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
