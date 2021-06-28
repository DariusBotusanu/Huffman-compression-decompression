#include "Node.h"

Node::Node(shared_ptr<Node> left, shared_ptr<Node> right, char symbol, unsigned int freq) :m_left{ left }, m_right{ right }, m_symbol{ symbol }, m_symbolFrequency{ freq }
{
}

Node::~Node()
{
}

ostream& operator<<(ostream& os, Node& node)
{
	os << "Node: " << node.m_symbol << " " << node.m_symbolFrequency;
	return os;
}
