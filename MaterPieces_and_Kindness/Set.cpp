#include "Set.h"
#include <iostream>
using namespace std;
Node::Node()
{}
Node::Node(Painting info, const int prev, const int next)
{
	this->info = info;
	this->next = next;
	this->prev = prev;
}
Node::~Node()
{}
void Node::setNext(const int n)
{
	this->next = n;
}
void Node::setPrev(const int p)
{
	this->prev = p;
}
void Node::setInfo(const Painting p)
{
	this->info = p;
}

////DOUBLY LINKED LIST ON ARRAY//////////////////////////////////////////////////////////

Set::Set()
{
	//creates a new empty set
	this->size = 0;
	this->capacity = 100;	
	this->head = -1;
	this->tail = -1;	
	this->free.add(-1);
	//for (int i = capacity-1; i >-1; i--)
	for(int i=0;i<capacity;i++)
		this->free.add(i);	
	this->firstEmpty = this->free.getHead()->getData();
	this->elems = new Node[capacity];
}

//destroys a set
Set::~Set()
{	
}
//adds a new element in the set
//If the set contains the element p, p is not added
void Set::add(const Painting p)
{	
	if (this->firstEmpty != -1)
	{
		this->size++;
		if (head == -1)
		{
			Node n{ p,-1,-1 };
			this->elems[this->firstEmpty] = n;
			this->head = firstEmpty;
			this->tail = firstEmpty;			
		}

		else
		{
			Node n{ p,this->tail,-1 };
			this->elems[firstEmpty] = n;
			this->elems[tail].setNext(firstEmpty);			
			this->tail = firstEmpty;			
		}	
		this->free.remove(firstEmpty);
		this->firstEmpty = this->free.getHead()->getData();
	}
	
}
//removes an element from the set
//If p not in set, no change is made
void Set::remove(const Painting p)
{
	int curent = this->head;
	while ((curent != -1) && (this->elems[curent].getInfo()!=p))
	{
		curent = this->elems[curent].getNext();
	}
	if (curent != -1)
	{
		this->size--;
		if (curent == this->head)
		{
			int nou = this->elems[curent].getNext();
			this->elems[nou].setPrev(-1);
			this->head = nou;			
		}
		if (curent == this->tail)
		{
			int nou = this->elems[curent].getPrev();
			this->elems[nou].setNext(-1);
			this->tail = nou;
		}
		if ((curent != this->head) && (curent != this->tail))
		{
			int inainte=this->elems[curent].getPrev();
			int dupa= this->elems[curent].getNext();
			this->elems[inainte].setNext(dupa);
			this->elems[dupa].setPrev(inainte);
		}		
		this->free.add(curent);
		this->firstEmpty = this->free.getHead()->getData();
	}
}
//verifies if an element is in the set
//return true if it is, false otherwise
bool Set::find(const Painting p)
{
	bool found = false;
	int curent = this->head;
	while ((curent != -1) && (found == false))
	{
		if (this->elems[curent].getInfo() == p)
			found = true;
		else
			curent = this->elems[curent].getNext();
	}
	return found;
}
//returns an iterator for the set s
Iterator Set::iterator() const 
{
	return Iterator(*this);
}

////    Iterator functions

Iterator::Iterator(const Set& s) :set(s)
{
	//this->current = s.getHead();
	this->current = s.getTail();
}
Iterator::~Iterator()
{}

Painting Iterator::getCurrent()
{
	return this->set.getAllElems()[this->current].getInfo();
}

void Iterator::next()
{
	//this->current = set.getAllElems()[this->current].getNext();
	this->current = set.getAllElems()[this->current].getPrev();
}
bool Iterator::valid()
{
	if (this->current == -1)
		return false;
	return true;
}

