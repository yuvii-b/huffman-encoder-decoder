#include <iostream>
#include "huffman.h"

int main(int argc, char* argv[]){
	HuffmanCoder *huff = new HuffmanCoder();
	std::string text;
	std::cout << "Enter the text to encode: ";
	std::getline(std::cin, text);
	std::cout << "Original text is: " << text << std::endl;
    huff->initialize(text);
	std::string encoded = huff->encode(text);
    std::cout << "Encoded: "  << encoded  << std::endl;
	std::string decoded = huff->decode(encoded);
	std::cout << "Decoded: "  << decoded << std::endl;
	huff->calculateCompressionStats(text, encoded);
	delete huff;
	return 0;
}
