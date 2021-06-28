#pragma once
#include <memory>
#include <iostream>

using namespace std;

class BinaryTree;
class HuffmanEncoder;

class Node{
	friend class BinaryTree;
	friend class HuffmanEncoder;
public:
	Node(shared_ptr<Node> left, shared_ptr<Node> right, char symbol, unsigned int freq);

	friend ostream& operator<<(ostream& os, Node& node);

	~Node();
private:
	shared_ptr<Node> m_left;
	shared_ptr<Node> m_right;
	char m_symbol;
	unsigned int m_symbolFrequency;
};
