#pragma once
#include "Set.h"
class UI
{
private:
	Set set;
	long int total;
	Painting last;
public:	
	UI(Set& s) : set{ s } {}
	~UI();
	void run();	
	static void printMenu();	
	void addPaint();
	void removePaint();
	void display();	
	void printEarnings();
	void updatePrice();
	void reinsert();
	Painting findObject(const std::string name);	
};

