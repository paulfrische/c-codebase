CC = clang
OUT = build
CFLAGS = -Wall -Wextra
SRCS = $(wildcard src/*.c src/**/*.c)
DEFINES = -DLOGGING

all:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(DEFINES) $(SRCS) -o $(OUT)/out

test: all
	./build/out

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
