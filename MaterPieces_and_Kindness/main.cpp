#pragma once
#include "SLL.h"
#include "Painting.h"
#include <assert.h>
#include "Ui.h"
#include <iostream>
using namespace std;
void test()
{	
	Painting p1 = Painting{ "Monalisa","Leonardo DaVinci",1756,800 };
	Painting p5= Painting{ "Monalisa","Leonardo DaVinci",1756,800 };
	Painting p3 = Painting{ "The Kiss","Gustav Klimt",1600,800 };
	assert(p1 == p5);
	assert(p1 != p3);
	assert(p1.getName() == "Monalisa");
	assert(p1.getAuthor() == "Leonardo DaVinci");
	assert(p1.getYear()==1756);
	assert(p1.getPrice()==800);
	assert(p1.toString() == "Monalisa Leonardo DaVinci 1756 800 mill");
	Painting p2= Painting{ "Venus Birth","Sandro Boticelli",1600,800};	
	LinkedList* list = new LinkedList();
	list->add(1);
	list->add(2);
	list->add(3);	
	list->remove(3);
	list->remove(1);	
	assert(list->getHead()->getData()==2);	
	delete list;
	Node n{ p1,-1,-1 };	
	assert(n.getInfo().getName()=="Monalisa");
	assert(n.getNext()==-1);
	n.setInfo(p2);
	assert(n.getInfo().getName() == "Venus Birth");
	Set lista;	
	lista.add(p1);
	assert(lista.getSize() == 1);	
	lista.add(p2);
	assert(lista.find(p2) == true);
	assert(lista.getSize() == 2);
	lista.add(p3);
	assert(lista.getSize()==3);
	Iterator it = lista.iterator();
	//assert(it.getCurrent().getName() == "Monalisa");
	it.next();
	//assert(it.valid()==true);
	assert(it.getCurrent().getName() == "Venus Birth");
	lista.remove(p2);
	assert(lista.getSize() == 2);
	lista.remove(p3);
	assert(lista.getSize() == 1);
	assert(lista.find(p2) == false);
	assert(lista.find(p3) == false);
	Iterator It2 = lista.iterator();
	//assert(It2.getCurrent().getName() ==p1.getName());
	lista.remove(p1);
	assert(lista.getSize() == 0);	
	Iterator It = lista.iterator();
	//assert(It.valid() == false);
	lista.add(p1);
	assert(lista.getSize() == 1);
}
void tes()
{
	Painting p1 = Painting{ "Monalisa","Leonardo DaVinci",1756,800 };
	Set set;
	set.add(p1);
	set.remove(p1);
	Iterator it =set.iterator();
	int i = 1;
	while (it.valid())
	{
		cout << i << "." << it.getCurrent().toString() << endl;
		it.next();
		i++;
	}
}
int main()
{
	system("color f4");
	test();	
	tes();
	Painting p1 = Painting{ "Monalisa","Leonardo DaVinci",1756,800 };
	Set set;	
	Painting p2 = Painting{ "Venus Birth","Sandro Boticelli",1600,900 };
	Painting p3 = Painting{ "The Kiss","Gustav Klimt",1600,800 };
	set.add(p1);
	set.add(p2);
	set.add(p3);
	UI ui(set);
	ui.run();		
	return 0;
}

