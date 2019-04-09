#include "Repo.h"
#include <string>

using namespace std;
Repository::Repository()
{}
Repository::~Repository()
{}
void Repository::addPainting(const Painting& s)
{
	this->paintings.add(s);
}

