#include "Utils.hpp"

#include "Span.hpp"

// In subject
// int main(void)
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }

// My test
int main(void)
{
	std::cout << Purple << "Test vector container"<< Reset_Color << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << Cyan << "Shortest span : " << Yellow << sp.shortestSpan() << std::endl;
		std::cout << Cyan << "Longest span : " << Yellow << sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << Purple << "Test vector range"<< Reset_Color << std::endl;
	Span sp2 = Span(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addNumber(v.begin(), v.end());
		std::cout << Cyan << "Shortest span : " << Yellow << sp2.shortestSpan() << std::endl;
		std::cout << Cyan << "Longest span : " << Yellow << sp2.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << Purple << "Test vector large range"<< Reset_Color << std::endl;
	Span sp3 = Span(100000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int random_int = rand() % 1000000000;
		v2.push_back(random_int);
	}
	try
	{
		sp3.addNumber(v2.begin(), v2.end());
		std::cout << Cyan << "Shortest span : " << Yellow << sp3.shortestSpan() << std::endl;
		std::cout << Cyan << "Longest span : " << Yellow << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
