CC = gcc

LDFLAGS = -lGL -lGLU -lGLEW -lglut
CFILES = $(shell find . -name "*.c")

hello: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o hello

.PHONY: run clean

run:
	./hello

clean:
	rm ./hello
