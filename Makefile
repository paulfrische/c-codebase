CC = clang
DEBUG_OUT = build/debug
RELEASE_OUT = build/release
CFLAGS = -Wall -Wextra
RELEASE_CFLAGS = -O2
SRCS = $(wildcard src/*.c src/**/*.c)
DEBUG_DEFINES = -DLOGGING
RELEASE_DEFINES =

all:
	mkdir -p $(DEBUG_OUT)
	$(CC) $(CFLAGS) $(DEBUG_DEFINES) $(SRCS) -o $(DEBUG_OUT)/main

release:
	mkdir -p $(RELEASE_OUT)
	$(CC) $(RELEASE_CFLAGS) $(RELEASE_DEFINES) $(SRCS) -o $(RELEASE_OUT)/main

test: all
	./build/debug/main

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
