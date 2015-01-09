LDFLAGS = -lGL -lGLU -lGLEW -lglut


triangles: triangles.cpp LoadShaders.cpp
	g++ triangles.cpp LoadShaders.cpp $(LDFLAGS) -o triangles


.PHONY: run

run:
	./triangles
