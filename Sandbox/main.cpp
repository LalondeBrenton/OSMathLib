#include <iostream>

#include "../OSMathLib/Fractions.h"
//using namespace OSMathLib;


int main()
{

	Fraction<int> f1 = { 1, 2 };
	Fraction<int> f2 = { 1, 6 };
	Fraction<int> f3;

	// 1/2 + 1/6 = 4/6
	f3 = f1 + f2;
	std::cout << f1 << " + " << f2 << " = " << f3 << "\n";
	// 1/2 - 1/6 = 2/6
	f3 = f1 - f2;
	std::cout << f1 << " - " << f2 << " = " << f3 << "\n";
	// 1/2 * 1/6 = 1/12
	f3 = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f3 << "\n";
	// 1/2 / 1/6 = 3/1
	f3 = f1 / f2;
	f3.reduce();
	std::cout << f1 << " / " << f2 << " = " << f3 << "\n";
	// 1/2 > 1/6
	if (f1 > f2)
		std::cout << f1 << " > " << f2 << "\n";
	else
		std::cout << f1 << " < " << f2 << "\n";


	return 0;
}