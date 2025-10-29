out: clean compile execute

compile: main.cpp data.cpp
	g++ -g -Wall -std=c++14 main.cpp data.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe