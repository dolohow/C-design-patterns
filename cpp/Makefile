CC=g++ -std=c++20
CFLAGS=-Wall -pthread

SRCS=$(wildcard *.cpp)
OBJS=${SRCS:.cpp=}

all: $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) $@.cpp -o $@

clean:
	rm -rf $(OBJS)
