#include "BinaryTree.h"
#include <iostream>
#include <queue>

BinaryTree::BinaryTree()
{
	m_root = nullptr;
}

BinaryTree::BinaryTree(shared_ptr<Node> root) : m_root{root}
{
}

shared_ptr<Node> BinaryTree::postorder(shared_ptr<Node> node)
{
	if (node == nullptr) {
		return nullptr;
	}
	else {
		return postorder(node->m_left);
		return postorder(node->m_right);
	}
}

void BinaryTree::displayPreorder(shared_ptr<Node> node)
{
	if (node != nullptr) 
	{
		cout << *node << endl;
		displayPreorder(node->m_left);
		displayPreorder(node->m_right);
	}
}

void BinaryTree::displayPostorder(shared_ptr<Node> node)
{
	if (node != nullptr)
	{
		displayPreorder(node->m_left);
		displayPreorder(node->m_right);
		cout << *node << endl;
	}
}

void BinaryTree::displayInorder(shared_ptr<Node> node)
{
	if (node != nullptr)
	{
		displayPreorder(node->m_left);
		cout << *node << endl;
		displayPreorder(node->m_right);
	}
}

shared_ptr<Node> BinaryTree::joinNodes(shared_ptr<Node> left, shared_ptr<Node> right)
{
	unsigned int frequency = 0;
	shared_ptr<Node> current = left;
	queue<shared_ptr<Node>> q;
	if (left.get() != nullptr) {
		q.push(left);
	}
	while (!q.empty()) 
	{
		shared_ptr<Node> current = q.back();
		q.pop();
		frequency += current->m_symbolFrequency;
		if (current->m_left.get() != nullptr) {
			q.push(current->m_left);
		}
		if (current->m_right.get() != nullptr) {
			q.push(current->m_right);
		}
	}

	if (right.get() != nullptr) {
		q.push(left);
	}
	while (!q.empty())
	{
		shared_ptr<Node> current = q.back();
		q.pop();
		frequency += current->m_symbolFrequency;
		if (current->m_left.get() != nullptr) {
			q.push(current->m_left);
		}
		if (current->m_right.get() != nullptr) {
			q.push(current->m_right);
		}
	}

	return make_shared<Node>(left, right, '*', frequency);
}

BinaryTree::~BinaryTree()
{
}
