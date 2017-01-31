CC=icpc
CFLAG=-g -Wall -std=c++11
BIN=Solution

SRC=$(wildcard *.cpp)

all: $(OBJ)
	$(CC) $(CFLAG) $(SRC) -o $(BIN)

clean:
	rm -f *.o
