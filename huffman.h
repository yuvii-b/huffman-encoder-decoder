#pragma once

#include <unordered_map>

class HuffmanNode{
	public:
		char ch;
		int freq;
		HuffmanNode *left, *right;

		HuffmanNode(char ch, int freq){
			this->ch = ch;
			this->freq = freq;
			left = nullptr;
			right = nullptr;
		}

		/* comparator to compare nodes by frequency */
		struct comparator{
			bool operator()(HuffmanNode *a, HuffmanNode *b){
				return a->freq > b->freq;
			}
		};
};

class HuffmanCoder{
	private:
		HuffmanNode *root;
		std::unordered_map<char, std::string> encoder;
		std::unordered_map<std::string, char> decoder;
		/* methods */
		std::unordered_map<char, int> buildCounter(const std::string&);
		void buildTree(const std::unordered_map<char, int>&);
		void initEncoderDecoder(HuffmanNode*, std::string);
	public:
		HuffmanCoder(){
			root = nullptr;
		}
		void initialize(const std::string&);
		std::string encode(const std::string&);
		std::string decode(const std::string&);
		void calculateCompressionStats(const std::string&, const std::string&);
		// more methods... (if needed)
};
