#include "Human.hpp"

Human::Human()
{
	return;
}

const void *Human::identify()
{
	return (this->brain.identify());
}

Brain Human::getBrain()
{
	return this->brain;
}

Human::~Human()
{
	return;
}