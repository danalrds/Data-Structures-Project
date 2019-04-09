#pragma once
#include <string>
class Painting
{
private:
	std::string name;
	std::string author;
	int year;
	double price;
public:
	Painting();	
	Painting(const std::string name, const std::string author, const int year, const double price);
	~Painting();
	std::string getName() const { return name; }
	std::string getAuthor() const { return author; }
	int getYear() const { return year; }
	double getPrice() const { return price; }
	std::string toString();
	bool operator==(const Painting& p);
	bool operator!=(const Painting& p);
};



