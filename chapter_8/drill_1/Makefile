output: use.o my.o
	g++ -std=c++11 use.cpp my.cpp -o output

use.o: use.cpp
	g++ -std=c++11 -c use.cpp

my.o: my.cpp my.h
	g++ -std=c++11 -c my.cpp

clean:
	rm *.o
