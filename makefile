output: main.o date.o
	g++ main.o date.o -o output

main.o: main.cpp
	g++ -c main.cpp

date.o: date.cpp date.h
	g++ -c date.cpp

clean:
	rm *.o output

