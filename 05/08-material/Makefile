TARGET = material
CC = gcc

LDFLAGS = -lm -lGL -lGLU -lglut 
DarwinLDFLAGS = -framework OpenGL -framework GLUT
CFILES = $(shell find . -name "*.c")

lines: $(CFILES)
	$(CC) $(CFILES) $(LDFLAGS) -o $(TARGET)

.PHONY: run clean

run: $(TARGET)
	./$(TARGET)

clean:
	rm ./$(TARGET)
