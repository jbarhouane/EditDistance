CC = g++
CFLAGS = -g --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-window -lsfml-graphics -lsfml-system

all: EDistance lint

lint:
	cpplint --recursive --quiet src/

EDistance: main.o EDistance.o
	$(CC) $(CFLAGS) -o EDistance main.o EDistance.o $(LIB)

EDistance.o: EDistance.cpp EDistance.hpp
	$(CC) $(CFLAGS) -c EDistance.cpp

main.o: main.cpp EDistance.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o EDistance

