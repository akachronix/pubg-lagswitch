CC=g++
CXXFLAGS=-Iinclude -Wall -pedantic -g

all: main.o LagSwitch.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) obj/main.o obj/LagSwitch.o -o bin/pubg-lagswitch -static

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

LagSwitch.o: src/LagSwitch.cpp
	$(CC) $(CXXFLAGS) -c src/LagSwitch.cpp

clean:
	rm -rf bin obj
