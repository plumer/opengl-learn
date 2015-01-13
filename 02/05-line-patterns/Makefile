CC = gcc

LDFLAGS = -lm -lGL -lGLU -lglut
DarwinLDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

lines: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o lines

.PHONY: run clean

run:
	./lines

clean:
	rm ./lines
