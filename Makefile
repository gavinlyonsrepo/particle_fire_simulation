# --- constants
CC=g++
CFLAGS=-Wall -g -c
LDFLAGS=-Wall -g -L /usr/lib/x86_64-linux-gnu -l SDL2
SOURCES = $(wildcard ./src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
BIN=./bin
INCLUDES=./include
TARGET=$(BIN)/pfsim


# --- Target of build process
all:	$(TARGET) clean

$(TARGET):	$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Make an .o from a .cpp
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< -iquote $(INCLUDES)
	
	
# --- Cleanup
#.PHONY: clean
clean:
	rm -vf $(OBJECTS)
