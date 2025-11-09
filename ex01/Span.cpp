#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() == _maxSize)
		throw std::runtime_error("Addition impossible: span is full");
	_numbers.push_back(number);
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Shortest span: not enough elements");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++)
		minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
	
	return (minSpan);
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Longest span: not enough elements");
	
	int	minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int	maxValue = *std::max_element(_numbers.begin(), _numbers.end());

	return (maxValue - minValue);
}
