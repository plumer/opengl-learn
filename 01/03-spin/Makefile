CC = gcc

LDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

double: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o double

.PHONY: run clean

run:
	./double

clean:
	rm ./double
