#pragma once
class Nod
{
private:
	Nod * next;
	int data;
public:
	int getData() { return data; }
	Nod* getNext() { return next; }
	void setData(int data);	
	void setNext(Nod* nextnode);
};



class LinkedList
{
private:	
	Nod* head;
public:
	LinkedList();
	~LinkedList();
	void add(int data);
	void remove(int data);	
	Nod* getHead() { return head; }		
};

