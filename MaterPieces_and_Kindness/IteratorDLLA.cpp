#include "IteratorDLLA.h"
IteratorDLLA::IteratorDLLA(const DLLA list)
{
	this->list = list;
	this->current = list.getHead();
}
IteratorDLLA::~IteratorDLLA()
{}
/*
Painting IteratorDLLA::getCurrent()
{
	return this->list.getAllElems[1];
}
*/
void IteratorDLLA::next()
{
	//this->current = this->list.getNext()[this->current];
}
bool IteratorDLLA::valid()
{
	if (this->current == -1)
		return false;
	else
		return true;
}