# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Src files
SRC = main.cpp huffman.cpp
OBJ = main.o huffman.o
TARGET = codec

# Target
all: $(TARGET)

# Linker
$(TARGET): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilation step
main.o: main.cpp Huffman.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Huffman.o: Huffman.cpp Huffman.h
	$(CXX) $(CXXFLAGS) -c huffman.cpp -o huffman.o

# Clean
clean:
	rm -f $(OBJ) $(TARGET) *.huff
