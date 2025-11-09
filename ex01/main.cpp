#include "Span.hpp"
#include <iostream>

static void	basicTest()
{
	std::cout << "=== Basic test ===\n" << std::endl;
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span -> " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span -> " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void	twoElementsTest()
{
	std::cout << "=== Two elements test ===\n" << std::endl;
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);

	std::cout << "Shortest span -> " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span -> " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void	bigTest()
{
	std::cout << "=== Big test ===\n" << std::endl;

	std::vector<int>	v;
	for (int i = 0; i < 10000; ++i)
		v.push_back(i);

	Span	big(10000);
	big.addRange(v.begin(), v.end());
	std::cout << "Shortest span -> " << big.shortestSpan() << std::endl;
	std::cout << "Longest span -> " << big.longestSpan() << std::endl;

	std::cout << std::endl;
}

static void	spanOverflowTest()
{
	std::cout << "=== Span overflow test ===\n" << std::endl;

	try
	{
		Span	sp(3);

		for (int i = 1; i < 4; i++)
			sp.addNumber(i * 10);
		sp.addNumber(40);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

static void	notEnoughTest()
{
	std::cout << "=== Not enough test ===\n" << std::endl;

	Span	sp(3);

	sp.addNumber(42);
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	basicTest();
	twoElementsTest();
	bigTest();
	spanOverflowTest();
	notEnoughTest();

	return (0);
}
