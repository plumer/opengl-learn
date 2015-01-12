CC = gcc

LDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

hello: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o hello

.PHONY: run clean

run:
	./hello

clean:
	rm ./hello
