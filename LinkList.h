#pragma once
#ifndef LinkList_h
#define LinkList_h

#include "Node.h"

class LinkList
{
public:
	LinkList();
	~LinkList();

	void show();
	void push(int);
	int pop();
	void insert(int, int);
	void remove(int);
	void replace(int, int);
	void swap(int, int);
	int first();
	int last();
	void sort(const char* = "acs");
	LinkList* find(int);
	int static number_of_linklists;
private:
	unsigned int len;
	Node* seed;
};

#endif // !LinkList_h
