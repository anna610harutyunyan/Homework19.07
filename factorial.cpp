#include <iostream>

template <unsigned int T>
class Factorial
{
public:
	static const unsigned int value = T * Factorial<T - 1>::value;
};

template <>
class Factorial<0>
{
public:
	static const unsigned int value = 1;
};

int main(int argc, char** argv)
{
	std::cout <<"Factorial of 7 is " << Factorial<7>::value <<std::endl;
	return 0;

}