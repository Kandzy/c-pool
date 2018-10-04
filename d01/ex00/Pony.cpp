#include "Pony.hpp"

Pony::Pony(str name, int age, str color, bool ammunition){
	this->name = name;
	this->age = age;
	this->color = color;
	this->ammunition = ammunition;
	if (this->ammunition)
	{
		this->status = true;
		pout << "Pony " + this->name + " color witch " + this->color + " ready to race. Ammunition prepeared." << nl;
	}
	else
	{
		this->status = false;
		pout << "Pony " + this->name + " color witch " + this->color + " not ready to race. Ammunition not prepeared." << nl;
	}
}

Pony::~Pony()
{
	if (this->status)
	{
		pout << "Pony " + this->name + " finished race!" << nl;
	}
	else
	{
		pout << "Pony " + this->name + " was disqualified!" << nl;
	}
	return ;
}

void Pony::setAmmunition(bool ammunition)
{
	this->ammunition = ammunition;
	if (this->ammunition)
	{
		pout << "Ammunition for " + this->name + " ready! Pony ready to race!" << nl;
		this->status = true;
	}
	else
	{
		pout << "Pony " + this->name + " dont have ammunition! Pony not ready to race!" << nl;
		this->status = false;
	}
}

void Pony::checkPonyIfReady(){
	if (this->status)
	{
		pout << this->name + " ready to race!" << nl;
	}
	else
	{
		pout << this->name + " not ready to race!" << nl;
	}
}
