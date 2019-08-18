#include <iostream>
#include <string>
#include "LinkList.h"

using namespace std;

LinkList::LinkList() {
	len = 0;
	seed = new Node();
	number_of_linklists++;
	//seed->setVal(v);
}

int LinkList::number_of_linklists=0;

LinkList::~LinkList() {
	//cout << "destructor" << endl;
	delete seed;
	number_of_linklists++;
}

void LinkList::show() {
	if (seed == nullptr) {
		cout << "This linklist is empty" << endl;
	} else {
		Node* temp = seed;
		cout << "  " << temp->getVal();
		while (temp->next != nullptr) {
			temp = temp->next;
			cout << "~" << temp->getVal();
		}
	}
	cout << endl;
}

void LinkList::push(int v) {
	if (len == 0)
	{
		seed->setVal(v);
	}
	else {
		Node* newNode = new Node;
		newNode->setVal(v);
		Node* temp = seed;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		newNode->prev = temp;
		temp->next = newNode;
	}
	len++;
}

int LinkList::pop() {
	int popVal = 0;
	if (len == 0)
	{
		cout << "The linklist is empty. Nothing to pop." << endl;
	}
	else
	{
		Node* temp = seed;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		popVal = temp->getVal();
		if(len!=1)
			temp->prev->next = nullptr;
		//temp->~Node();
		len--;
	}
	return popVal;
}

void LinkList::insert(int v, int ind) {
	if (ind <= len + 1 && ind > 0)
	{
		if (len == 0)
		{
			push(v);
		}
		else
		{
			Node* temp = seed, * newNode = new Node();
			int i = 1;
			while (i != ind)
			{
				temp = temp->next;
				i++;
			}
			newNode->setVal(v);
			temp->prev->next = newNode;
			newNode->prev = temp->prev;
			temp->prev = newNode;
			newNode->next = temp;
			len++;
		}
	}
	else {
		cout << "index is out of band!";
	}
}

void LinkList::remove(int ind) {
	if (ind <= len && ind > 0)
	{
		Node* temp = seed;
		int i = 1;
		while (i != ind)
		{
			temp = temp->next;
			i++;
		}
		if (len!=1)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		delete temp;
		//seed->~Node();
		len--;
	}
	else {
		cout << "There is no index with number " << ind << endl;
	}
}

void LinkList::replace(int v, int ind) {
	if (ind <= len && ind > 0)
	{
		Node* temp = seed;
		for (int i = 0; i < len; i++)
		{
			if (i == ind - 1)
			{
				temp->setVal(v);
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	else {
		cout << "index is out of band!";
	}
}

void LinkList::swap(int first, int second) {
	int smaller = 0, bigger = 0;
	bool check = true;

	if (first > len || first < 0 || second > len || second < 0)
	{
		check = false;
		cout << "Input values are out of band!" << endl;
	}
	else
	{
		if (first < second) {
			smaller = first;
			bigger = second;
		}
		else if (second < first)
		{
			smaller = second;
			bigger = first;
		}
		else
		{
			cout << "Both index are the same!" << endl;
			check = false;
		}
	}

	if (check)
	{
		Node* temp = seed, * pSmall = new Node();
		int rep;
		int i = 1;
		while (temp->next != nullptr)
		{
			if (i == smaller)
			{
				pSmall = temp;
			}
			temp = temp->next;
			i++;
			if (i == bigger)
			{
				break;
			}
		}
		rep = pSmall->getVal();
		pSmall->setVal(temp->getVal());
		temp->setVal(rep);
	}
}

int LinkList::first()
{
	int first = 0;
	if (len == 0)
	{
		cout << "The linklist is empty!" << endl;
	}
	else
	{
		first = seed->getVal();
		//seed->next->prev = nullptr;
		if (seed->next!=nullptr)
		{
			seed = seed->next;
			delete seed->prev;
			seed->prev = nullptr;
		}
		else
		{
			seed = new Node;
		}
		len--;
	}
	return first;
}

int LinkList::last()
{
	int last = 0;
	if (len == 0)
	{
		cout << "The linklist is empty!" << endl;
	}
	else
	{
		if (seed->next == nullptr)
		{
			last = seed->getVal();
			seed = new Node;
		}
		else
		{
			Node* temp = seed;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			last = temp->getVal();
			temp->prev->next = nullptr;
			delete temp;
		}
		len--;
	}
	return last;
}
//
void LinkList::sort(const char* type)
{
	if (len == 0)
	{
		cout << "The linklist is empty!" << endl;
	}
	else
	{
		for (int i = len; i > 1; i--)
		{
			Node* temp = seed;
			int j = 1;
			//while (temp->next != nullptr && j < i)
			while (j < i)
			{
				if (_strcmpi(type, "acs")==0)
				{
					if (temp->getVal() > temp->next->getVal())
					{
						swap(j, j + 1);
					}
				}
				else
				{
					if (temp->getVal() < temp->next->getVal())
					{
						swap(j, j + 1);
					}
				}
				temp = temp->next;
				j++;
			};
		}
	}
}


LinkList* LinkList::find(int v)
{
	LinkList* lili = new LinkList();
	Node* temp = seed;
	int index = 0;
	while (temp != nullptr)
	{
		if (v == temp->getVal())
		{
			lili->push(index);
		}
		index++;
		temp = temp->next;
	}
	return lili;
}