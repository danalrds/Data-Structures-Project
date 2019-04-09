#include "SLL.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void Nod::setData(int data)
{
	this->data = data;
}
void Nod::setNext(Nod* nextnode)
{
	this->next = nextnode;
}

LinkedList::LinkedList() 
{	
	this->head = NULL;
}

LinkedList::~LinkedList() 
{	
}

void LinkedList::add(int data) 
{
	Nod* node = new Nod();	
	node->setData(data);	
	node->setNext(this->head);
	this->head = node;	
}

void LinkedList::remove(int data)
{
	Nod* curent = this->head;
	Nod* prev = NULL;
	while ((curent != NULL) && (curent->getData() != data))
	{
		prev = curent;
		curent = curent->getNext();
	}
	if (prev == NULL)
	{
		if (this->head != NULL)
		{
			this->head = this->head->getNext();
		}			
	}
	else if (curent != NULL)
	{
		prev->setNext(curent->getNext());
		curent->setNext(NULL);
	}		
}

