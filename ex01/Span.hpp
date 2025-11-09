#pragma once

#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;
	
	Span();
public:
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void	addNumber(int number);

	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _numbers.size() > _maxSize)
			throw std::runtime_error("Iterator range is too big");
		_numbers.insert(_numbers.end(), begin, end);
	}

	int		shortestSpan() const ;
	int		longestSpan() const ;
};
