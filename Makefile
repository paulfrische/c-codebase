CC = clang
OUT = build
CFLAGS = -Wall -Wextra
SRCS = $(wildcard src/*.c src/**/*.c)
DEFINES = -DLOGGING

all:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(DEFINES) $(SRCS) -o $(OUT)/main

test: all
	./build/main

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
