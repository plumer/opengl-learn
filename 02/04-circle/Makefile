CC = gcc

LDFLAGS = -lm -lGL -lGLU -lglut
DarwinLDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

circle: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o circle

.PHONY: run clean

run:
	./circle

clean:
	rm ./circle
