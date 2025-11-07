#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"
#include "easyfind.tpp"

int main()
{
	try
	{
		std::vector<int>	vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i * 2);

		std::cout << "Testing std::vector" << std::endl;
		std::cout << "Looking for 4 -> " << *easyfind(vec, 4) << std::endl;
		std::cout << "Looking for 8 -> " << *easyfind(vec, 8) << std::endl;

		try
		{
			std::cout << "Looking for 7 -> ";
			easyfind(vec, 7);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::list<int>	lst;
		for (int i = 10; i < 15; i++)
			lst.push_back(i);

		std::cout << "\nTesting std::list" << std::endl;
		std::cout << "Looking for 12 -> " << *easyfind(lst, 12) << std::endl;

		try
		{
			std::cout << "Looking for 42 -> ";
			easyfind(lst, 42);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::deque<int> dq;
		for (int i = 3; i < 9; i++)
			dq.push_back(i);

		std::cout << "\nTesting std::deque" << std::endl;
		std::cout << "Looking for 5 -> " << *easyfind(dq, 5) << std::endl;

	}
	catch (const std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
	
	return (0);
}
