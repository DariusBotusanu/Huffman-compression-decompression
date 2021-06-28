#pragma once
#include <string>
#include "BinaryTree.h"

using namespace std;

#define ALPHABET_SIZE  256
class HuffmanEncoder
{
public:
	HuffmanEncoder(string src);

	void computeHistogram();
	shared_ptr<Node> computeHuffmanTree();
	string* encode();

private:
	string m_srcFile;
	BinaryTree m_huffmanTree;
	unsigned int* m_histogram[ALPHABET_SIZE];
};

