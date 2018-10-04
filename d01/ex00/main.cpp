#include "Pony.hpp"

void ponyOnTheHeap(void)
{
	Pony *ponyHeap = new Pony("Ashe", 3, "Brown", true);
	ponyHeap->checkPonyIfReady();
	ponyHeap->setAmmunition(false);
	ponyHeap->checkPonyIfReady();
	delete ponyHeap;
}

void ponyOnTheStack(void)
{
	Pony ponyStack = Pony("Nami", 2, "White", false);
	ponyStack.checkPonyIfReady();
	ponyStack.setAmmunition(true);
	ponyStack.checkPonyIfReady();
}

int main()
{
	pout << "***************************************" 
		<< nl << "        >> Pony on the Heap  <<" << nl
		<< "***************************************" << nl;
	ponyOnTheHeap();
	pout << nl;
	pout << "***************************************" 
		<< nl << "        >> Pony on the Stack <<" << nl
		<< "***************************************" << nl;
	ponyOnTheStack();
	return (0);
}