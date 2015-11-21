g++ = g++ -std=c++11
rm = rm -rf

all: prepare singleton adapter

clean:
	$(rm) build

prepare:
	mkdir -p build

singleton:
	$(g++) -pthread singleton.cpp -o build/singleton
adapter:
	$(g++) adapter.cpp -o adapter -o build/adapter

