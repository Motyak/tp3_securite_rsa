CC=g++
CFLAGS=--std=c++11
SRC=src/exo4.cpp src/exo5.cpp
EXEC=bin/exo4 bin/exo5
DIRS=bin

all: $(EXEC)

bin/exo4: src/exo4.cpp
	$(CC) -o bin/exo4 src/exo4.cpp $(CFLAGS)

bin/exo5: src/exo5.cpp
	$(CC) -o bin/exo5 src/exo5.cpp $(CFLAGS)

clean:
	rm -rf bin

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))
