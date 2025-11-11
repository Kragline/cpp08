#include "easyfind.hpp"

template <typename T>
typename	T::iterator	easyfind(T &containter, int value)
{
	typename T::iterator	it = std::find(containter.begin(), containter.end(), value);

	if (it == containter.end())
		throw std::runtime_error("Value not found in the container");
	return (it);
}
