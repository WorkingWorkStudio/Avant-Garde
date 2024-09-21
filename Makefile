CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -g

OpenTest: ./src/main.cpp
	glslc src/shaders/shader.vert -o vert.spv
	glslc src/shaders/shader.frag -o frag.spv
	g++ $(CFLAGS) src/*.cpp -o a.out $(LDFLAGS)

.PHONY: test clean

test: OpenTest
	./a.out

clean:
	rm -f a.out
	rm -rf *.o
	rm -rf *.spv
