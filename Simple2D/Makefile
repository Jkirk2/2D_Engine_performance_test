CXX = g++
CXXFLAGS = -Wall
LIBS = -lsimple2d -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf
main: ball.o main.cpp
	$(CXX) $(CXXFLAGS) ball.o main.cpp $(LIBS) -o main

ball.o: ball.h ball.cpp
	$(CXX) $(CXXFLAGS) -c ball.cpp $(LIBS)

run:
	./main

clean:
	-rm -f *~ *.o

val:
	valgrind ./main