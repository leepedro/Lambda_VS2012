#include <list>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

void FindFirstEvenNumber(void)
{
	//std::array<int, 5> numbers = {13, 17, 42, 46, 99};
	//std::vector<int> numbers {13, 17, 42, 46, 99};	// C+11
	std::vector<int> numbers;
	numbers.push_back(13);
	numbers.push_back(17);
	numbers.push_back(42);
	numbers.push_back(46);
	numbers.push_back(99);
	
	// Call std::find_if function with a lambda expression.
	// This works with or without capture clause [=] or [&] because it does not really change anything outside.
	// Single return does not require '-> return type'.
	//const std::vector<int>::const_iterator result = std::find_if(numbers.begin(), numbers.end(), [=](int n) { return (n % 2) == 0; });
	//const std::vector<int>::const_iterator result = std::find_if(numbers.begin(), numbers.end(), [&](int n) { return (n % 2) == 0; });
	const std::vector<int>::const_iterator result = std::find_if(numbers.begin(), numbers.end(), [](int n) -> bool { return (n % 2) == 0; });

	if (result != numbers.end())
	{
		std::cout << "The first even number is " << *result << "." << std::endl;
	}
	else
	{
		std::cout << "There is no even numbers." << std::endl;
	}
}

void AddTwoNumbers(void)
{
	// Declare and define a function object with a lambda expression.
	auto functor1 = [] (int x, int y) { return x + y; };

	// Invoke the lambda function (function object?)
	std::cout << functor1(21, 22) << std::endl;
}

template <typename T>
void NegateAll(std::vector<T> &data)
{
	std::for_each(data.begin(), data.end(), [] (T &n) { n = -n; });
}

template <typename T>
void PrintAll(const std::vector<T> &data)
{
	std::for_each(data.begin(), data.end(), [] (const T &n) { std::cout << n << std::endl; });
}

void UseTemplate(void)
{
	//std::vector<int> numbers {13, 17, 42, 46, 99};	// C+11
	std::vector<int> numbers;
	numbers.push_back(13);
	numbers.push_back(17);
	numbers.push_back(42);
	numbers.push_back(46);
	numbers.push_back(99);

	NegateAll(numbers);
	PrintAll(numbers);
}

int main(void)
{
	FindFirstEvenNumber();
	AddTwoNumbers();
	UseTemplate();
}