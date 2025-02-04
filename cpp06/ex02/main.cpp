#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Utils.hpp"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Other function
Base *generate(void)
{
	std::srand(std::time(0) + std::rand());
	int random = std::rand() % 3;

	// std::cout << random << std::endl;
	if (random == 0)
	{
		return (new A());
	}
	else if (random == 1)
	{
		return (new B());
	}
	else if (random == 2)
	{
		return (new C());
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A";
	}
	catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B";
	}
	catch (std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C";
	}
	catch (std::exception &e) {
	}
}

// Main
int main(void)
{
	Base *base = generate();

	// Pointer
	std::cout << Cyan << "Pointer : " << Yellow;
	identify(base);
	std::cout << Reset_Color << std::endl;

	// Reference
	std::cout << Cyan << "Reference : " << Yellow;
	identify(*base);
	std::cout << Reset_Color << std::endl;

	delete base;
	return (0);
}
