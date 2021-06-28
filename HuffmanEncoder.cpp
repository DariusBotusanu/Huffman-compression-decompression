#include "HuffmanEncoder.h"
#include <queue>
#include <fstream>
#include <vector>

HuffmanEncoder::HuffmanEncoder(string src)
{
	m_srcFile = src;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		m_histogram[i] = 0;
	}
}

void HuffmanEncoder::computeHistogram()
{
	ifstream originalFile(m_srcFile);
	while (originalFile) {
		unsigned char c;
		originalFile >> c;
		m_histogram[c]++;
	}
}

shared_ptr<Node> HuffmanEncoder::computeHuffmanTree()
{
	m_histogram[0]++;
	m_histogram[255]++;

	auto compareNodes = [this](shared_ptr<Node> n1, shared_ptr<Node> n2) { return n1->m_symbolFrequency < n2->m_symbolFrequency; };
	priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(compareNodes)> q(compareNodes);

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		q.push(make_shared<Node>(nullptr, nullptr, i, m_histogram[i]));
	}
	while (q.size() >= 2) {
		shared_ptr<Node> left = q.top(); q.pop();
		shared_ptr<Node> right = q.top(); q.pop();
		shared_ptr<Node> parent = m_huffmanTree.joinNodes(left, right);
		q.push(parent);
	}
	m_huffmanTree.m_root = q.top(); q.pop();
	return m_huffmanTree.m_root;
}

string* HuffmanEncoder::encode()
{
	string* encodedArray[ALPHABET_SIZE];
	m_histogram[0]--;
	m_histogram[255]--;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (m_histogram[i] != 0) {
			string encoded; //Trying to figure out how to encode
			while()
		}
	}
}
