#include <iostream>

#include "../OSMathLib/OSMathLib.h"
using namespace OSMathLib;


int main()
{
	fraction<int> f1 = { 99, 50 };
	fraction<float> f2 = { 5.1, 10.1 };
	fraction<float> f3;
	fraction<float> f4 = f2;
	f3 = f2;

	std::cout << f1 << " and " << f2 << " and " << f3 <<"\n";

	return 0;
}