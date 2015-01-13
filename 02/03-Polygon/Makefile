CC = gcc

LDFLAGS = -lGL -lGLU -lglut
DarwinLDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

polygon: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o polygon

.PHONY: run clean

run:
	./polygon

clean:
	rm ./polygon
