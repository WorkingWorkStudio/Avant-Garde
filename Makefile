CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -Xrandr - lXi

OpenTest: main.cpp
	g++ $(CFLAGS) *.cpp -o a.out $(LDFLAGS)

.PHONY: test clean

test: OpenTest
	./a.out

clean:
	rm -f a.out
