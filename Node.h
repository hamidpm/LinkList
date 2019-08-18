#pragma once
#ifndef Node_h
#define Node_h

class Node {
public:
	Node();
	~Node();
	int getVal() const;
	void setVal(int);
	Node* next,* prev;
private:
	int val;
};

#endif // !Node_h

