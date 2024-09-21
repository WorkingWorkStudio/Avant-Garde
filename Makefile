CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

OpenTest: main.cpp
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv
	g++ $(CFLAGS) *.cpp -o a.out $(LDFLAGS) -g

.PHONY: test clean

test: OpenTest
	./a.out

clean:
	rm -f a.out
	rm -rf *.o
	rm -rf ./shaders/*.spv
