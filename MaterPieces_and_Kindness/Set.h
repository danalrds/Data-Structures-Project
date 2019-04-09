#pragma once
#include "Painting.h"
#include "SLL.h"
class Node
{
private:
	Painting info;
	int next;
	int prev;
public:
	Node();
	Node(Painting info, const int prev, const int next);
	~Node();
	Painting getInfo() const { return info; }
	int getNext() const { return next; }
	int getPrev() const { return prev; }
	void setNext(const int n);
	void setPrev(const int p);
	void setInfo(const Painting p);
};


class Iterator;
class Set
{
private:
	Node * elems;	
	int capacity;
	int size;
	int head;
	int tail;
	int firstEmpty;
	LinkedList free;
	Node* getAllElems() const { return this->elems; };
	int getHead() const { return head; }
	int getTail() const { return tail; }
public:
	friend class Iterator;
	Set();	
	~Set();	
	void add(const Painting p);
	void remove(const Painting e);	
	int getSize() const { return size; };	
	bool find(const Painting p);
	Iterator iterator() const;
};

/////////////////////          ITERATOR
class Iterator
{
private:
	Iterator(const Set& s);
	const Set& set;
	int current;
public:
	friend class Set;
	~Iterator();
	Painting getCurrent();
	void next();
	bool valid();
};


