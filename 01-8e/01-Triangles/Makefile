LDFLAGS = -lGL -lGLU -lglut -lGLEW
TARGET = triangles

$(TARGET): triangles.cpp LoadShaders.cpp
	g++ triangles.cpp LoadShaders.cpp $(LDFLAGS) -o $(TARGET)


.PHONY: run clean

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET)
