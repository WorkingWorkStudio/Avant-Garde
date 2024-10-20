CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi


ifeq ($(DEBUG), 0)
	# enable wireframe
	DEBUGFLAGS = -g
else ifeq ($(DEBUG), 1)
	DEBUGFLAGS = -g -DLINE
else
	DEBUGFLAGS = -g
endif

OpenTest: ./src/main.cpp
	glslc src/shaders/shader.vert -o vert.spv
	glslc src/shaders/shader.frag -o frag.spv
	g++ $(CFLAGS) src/main.cpp src/render/*.cpp -o a.out $(LDFLAGS) $(DEBUGFLAGS)

.PHONY: test clean

test: OpenTest
	./a.out

clean:
	rm -f a.out
	rm -rf *.o
	rm -rf *.spv
