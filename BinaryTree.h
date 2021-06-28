#pragma once
#include "Node.h"

class HuffmanEncoder;

class BinaryTree
{
	friend class HuffmanEncoder;
public:
	BinaryTree();
	BinaryTree(shared_ptr<Node> root);

	shared_ptr<Node> postorder(shared_ptr<Node> node);

	void displayPreorder(shared_ptr<Node> node);
	void displayPostorder(shared_ptr<Node> node);
	void displayInorder(shared_ptr<Node> node);

	static shared_ptr<Node> joinNodes(shared_ptr<Node> left, shared_ptr<Node> right);

	inline shared_ptr<Node>& getRoot() { return m_root; }

	~BinaryTree();
private:
	shared_ptr<Node> m_root;
};

