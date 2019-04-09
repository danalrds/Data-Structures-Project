#include "Ui.h"
#include <string>
#include <iostream>
using namespace std;
UI::~UI()
{}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Add painting." << endl;
	cout << "2 - Remove painting." << endl;
	cout << "3 - Update price" << endl;
	cout << "4 - Reinsert and remove another." << endl;
	cout << "5 - Show earnings." << endl;
	cout << "6 - Display" << endl;
	cout << "0 - Exit." << endl;
}


void UI::addPaint()
{
	cin.ignore();
	int year;
	double price;
	cout << "Enter name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the author: ";
	std::string author;
	getline(cin, author);	
	cout << "Enter year: ";
	cin >> year;	
	cout << "Enter price: ";
	cin >> price;
	Painting P{ name, author, year,price };
	if (this->set.find(P) == false)
		this->set.add(P);
	else
		cout << "The painting is a fake. We can not add it!" << endl;
}

void UI::removePaint()
{
	cin.ignore();	
	cout << "Enter name: ";
	std::string name;
	getline(cin, name);	
	Painting p = findObject(name);
	if (p.getName()!="")
	{
		this->last = p;
		this->total = this->total + p.getPrice();
		this->set.remove(p);
	}
	else
		cout << "The painting was already sold!" << endl;

}
 
Painting UI::findObject(const std::string name)
{
	Iterator it = this->set.iterator();
	while (it.valid())
	{
		if (it.getCurrent().getName() == name)
		{
			return it.getCurrent();	
		}
		it.next();
	}	
	return Painting{};
}

void UI::printEarnings()
{
	cout << "Earnings are " << this->total << " mill$" << endl;
}
void UI::updatePrice()
{
	cin.ignore();
	cout << "Enter name: ";
	std::string name;
	getline(cin, name);
	double price;
	cout << "Enter new price ";
	cin >> price;	
    Painting p = findObject(name);
	if (p.getName() != "")
	{
		Painting nou{ name, p.getAuthor(), p.getYear(), price };
		this->set.remove(p);
		this->set.add(nou);
	}
	else
		cout << "The painting was already sold!" << endl;
}

void UI::reinsert()
{
	cin.ignore();
	cout << "Enter name: ";
	std::string name;
	getline(cin, name);
	if (name == this->last.getName())
	{
		cout << "Enter the name of the painting you want to change with: ";
		std::string newname;
		getline(cin, newname);
		Painting paint=findObject(newname);
		if (paint.getName()!="")
		{
			this->total = this->total - this->last.getPrice();
			this->set.add(this->last);			
			this->last = paint;
			this->total = this->total + paint.getPrice();
			this->set.remove(paint);
			cout << "The change was successfull!" << endl;
		}
		else
			cout << "The painting was already sold!" << endl;
	}
	else
		cout << "This is not the last sold painting!" << endl;
}
void UI::display()
{
	Iterator it = this->set.iterator();
	int i = 1;
	while (it.valid()) 
	{
		cout << i<<"."<<it.getCurrent().toString()<<endl;
		it.next();
		i++;
	}
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command;
		cout << "Input the command: ";
		cin >> command;		
		if (command == 0)
			break;		
		if (command == 1)
		{
			this->addPaint();
		}		
		if (command == 2)
		{
			this->removePaint();
		}
		if (command == 3)
		{
			this->updatePrice();
		}
		if (command == 4)
		{
			this->reinsert();
		}
		if (command == 5)
		{
			this->printEarnings();
		}			
		if (command == 6)
		{
			this->display();
		}
		
	}
}