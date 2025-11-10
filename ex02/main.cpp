#include "MutantStack.hpp"
#include <iostream>

template <typename T>
static void	regularTest(MutantStack<T> mStack)
{
	std::cout << "=== Regular iterators ===\n" << std::endl;

	MutantStack<int>::iterator	it = mStack.begin();
	MutantStack<int>::iterator	ite = mStack.end();

	++it;
	--it;

	*it = 99;
	std::cout << "Element pointed by begin iterator was changed to 99" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
}

template <typename T>
static void	constTest(MutantStack<T> mStack)
{
	std::cout << "=== Const iterators ===\n" << std::endl;

	MutantStack<int>::const_iterator	cIt = mStack.begin();
	MutantStack<int>::const_iterator	cItE = mStack.end();

	++cIt;
	--cIt;

	// Won't compile if comment is removed
	// *cIt = 99;

	while (cIt != cItE)
	{
		std::cout << *cIt << std::endl;
		++cIt;
	}

	std::cout << std::endl;
}

template <typename T>
static void	reverseTest(MutantStack<T> mStack)
{
	std::cout << "=== Reverse iterators ===\n" << std::endl;

	MutantStack<int>::reverse_iterator	rIt = mStack.rbegin();
	MutantStack<int>::reverse_iterator	rItE = mStack.rend();

	++rIt;
	--rIt;

	*rIt = 99;
	std::cout << "Element pointed by reverse begin iterator was changed to 99" << std::endl;

	while (rIt != rItE)
	{
		std::cout << *rIt << std::endl;
		++rIt;
	}

	std::cout << std::endl;
}

template <typename T>
static void	constReverseTest(MutantStack<T> mStack)
{
	std::cout << "=== Const reverse iterators ===\n" << std::endl;

	MutantStack<int>::const_reverse_iterator	cRevIt = mStack.rbegin();
	MutantStack<int>::const_reverse_iterator	cRevItE = mStack.rend();

	++cRevIt;
	--cRevIt;

	// Won't compile if comment is removed
	// *cRevIt = 99;

	while (cRevIt != cRevItE)
	{
		std::cout << *cRevIt << std::endl;
		++cRevIt;
	}

	std::cout << std::endl;
}

int	main()
{
	std::cout << "=== Creating stack and pushing elements ===\n" << std::endl;

	MutantStack<int>	mStack;

	for (size_t i = 0; i < 2; i++)
	{
		mStack.push(i * 10);
		std::cout << i * 10 << " was pushed to stack" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Size of stack -> " << mStack.size() << std::endl;
	int	topElement = mStack.top();
	std::cout << "Top of stack -> " << topElement << std::endl << std::endl;

	mStack.pop();
	std::cout << topElement << " was popped from stack" << std::endl << std::endl;

	std::cout << "Size of stack after pop -> " << mStack.size() << std::endl;
	std::cout << "Top of stack after pop -> " << mStack.top() << std::endl << std::endl;
	
	for (size_t i = 1; i < 10; i++)
	{
		mStack.push(i * 10);
		std::cout << i * 10 << " was pushed to stack" << std::endl;
	}
	std::cout << std::endl;

	regularTest<int>(mStack);
	constTest<int>(mStack);
	reverseTest<int>(mStack);
	constReverseTest<int>(mStack);

	std::cout << "=== Tests were completed ===" << std::endl;

	return (0);
}
