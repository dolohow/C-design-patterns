g++ = g++ -std=c++11
singleton:
	$(g++) -pthread singleton.cpp -o singleton

all: singleton
