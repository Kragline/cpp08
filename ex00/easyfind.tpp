#include "easyfind.hpp"

template <typename Iterator>
typename	Iterator::iterator	easyfind(Iterator &containter, int value)
{
	typename Iterator::iterator	it = std::find(containter.begin(), containter.end(), value);

	if (it == containter.end())
		throw std::runtime_error("Value not found in the container");
	return (it);
}
