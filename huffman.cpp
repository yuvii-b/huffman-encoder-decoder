#include <iostream>
#include <unordered_map>
#include <queue>
#include "huffman.h"

std::unordered_map<char, int> HuffmanCoder::buildCounter(const std::string &text){
	std::unordered_map<char, int> counter;
	for(char ch : text){
		counter[ch]++;
	}
	return counter;
}

void HuffmanCoder::buildTree(const std::unordered_map<char, int> &counter){
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNode::comparator> minHeap;
	for(const auto &pair : counter){
		minHeap.push(new HuffmanNode(pair.first, pair.second));
	}
	while(minHeap.size() != 1){
		HuffmanNode *left = minHeap.top();
		minHeap.pop();
		HuffmanNode *right = minHeap.top(); /* left and right are interchangeable */
		minHeap.pop();
		HuffmanNode *newNode = new HuffmanNode('\0', left->freq + right->freq);
		newNode->left = left;
		newNode->right = right;
		minHeap.push(newNode);
	}
	this->root = minHeap.top();
}

void HuffmanCoder::initEncoderDecoder(HuffmanNode *node, std::string code){
	if(!node) return;
	if(!node->left && !node->right){
		this->encoder[node->ch] = code;
		this->decoder[code] = node->ch;
		return;
	}
	initEncoderDecoder(node->left, code + "0");
	initEncoderDecoder(node->right, code + "1");
}

void HuffmanCoder::initialize(const std::string &text){
	this->buildTree(this->buildCounter(text));
	this->initEncoderDecoder(root, "");
	/* debug code: 
	std::cout << "Encoder table: " << std::endl;
	for(auto &pair : this->encoder){
		std::cout << "Character: " << pair.first << " -> Code: " << pair.second << std::endl;
	} */
}

std::string HuffmanCoder::encode(const std::string &plainText){
	std::string ans = "";
	for(char ch : plainText){
		ans += this->encoder[ch];
	}
	return ans;
}

std::string HuffmanCoder::decode(const std::string &codedStr){
	std::string ans = "";
	std::string key = "";
	for(char ch : codedStr){
		key += ch;
		if(this->decoder.find(key) != this->decoder.end()){
			/* debug code:
			std::cout << "Decoding: " << key << " -> " << this->decoder[key] << std::endl; */
			ans += this->decoder[key];
			key = "";
		}
	}
	return ans;
}

