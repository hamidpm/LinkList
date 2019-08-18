#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() {
	val = 0;
	next = nullptr;
	prev = nullptr;
}

Node::~Node() {
	cout << "destructor " << this->getVal() << endl;
	next = nullptr;
	prev = nullptr;
}

void Node::setVal(int v) {
	val = v;
}

int Node::getVal() const {
	return val;
}