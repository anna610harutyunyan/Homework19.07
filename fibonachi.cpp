#include <iostream>

template <unsigned int T>

struct Fibonachi
{
	static const  int result = Fibonachi<T - 1>::result + Fibonachi<T - 2>::result;
};

template<>
struct Fibonachi<0>
{
	static const int result = 0;
};
template<>
struct Fibonachi<1>
{
	static const int result = 1;
};

int main(int argc, char** argv)
{
	std::cout << "The 7th member of fibonachi sequence is " << Fibonachi<7>::result << std::endl;

	return 0;
}