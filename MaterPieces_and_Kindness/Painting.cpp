#include "Painting.h"
#include <iostream>
#include <sstream>
using namespace std;
Painting::Painting() : name(""), author(""), year(0), price(0)
{}

Painting::Painting(const std::string name, const std::string author, const int year, const double price) 
{
	this->name = name;
	this->author = author;
	this->year = year;
	this->price = price;
}
Painting::~Painting()
{}
std::string Painting::toString()
{
	stringstream buffer;
	buffer << this->getName() << " " << this->getAuthor() << " " << this->getYear() << " " << this->getPrice()<<" mill";
	return buffer.str();
}

bool Painting ::operator==(const Painting& p)
{
	return(this->getName() == p.getName());
}

bool Painting ::operator!=(const Painting& p)
{
	return(this->getName() != p.getName());
}