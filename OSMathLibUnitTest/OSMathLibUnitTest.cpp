#include "CppUnitTest.h"

#include "../OSMathLib/Fractions.h"
#include "../OSMathLib/ComplexNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace OSMathLib;

namespace OSMathLibUnitTest
{
	TEST_CLASS(OSMathLibUnitTest)
	{
	public:

		TEST_METHOD(TestFractionArithmatic)
		{
			Fraction<int> f1 = { 1, 2 };
			Fraction<int> f2 = { 1, 6 };
			Fraction<int> f3;
			Logger::WriteMessage("Testing fraction arithmetics.");
			// 1/2 + 1/6 = 4/6
			f3 = f1 + f2;
			Assert::IsTrue(Fraction<int>(4, 6) == f3);
			// 1/2 - 1/6 = 2/6
			f3 = f1 - f2;
			Assert::IsTrue(Fraction<int>(2, 6) == f3);
			// 1/2 * 1/6 = 1/12
			f3 = f1 * f2;
			Assert::IsTrue(Fraction<int>(1, 12) == f3);
			// 1/2 / 1/6 = 3/1
			f3 = f1 / f2;
			f3.reduce();
			Assert::IsTrue(Fraction<int>(3) == f3);
			// 1/2 > 1/6
			Assert::IsTrue(f1 > f2);
			// 1/2 > 1/6
			Assert::IsTrue(f2 < f1);
		}

		TEST_METHOD(TestComplexNumbersArithmatic)
		{
			ComplexNumber<int> f1 = { 1, 0 };
			ComplexNumber<int> f2 = { 0, 1 };
			ComplexNumber<int> f3;
			Logger::WriteMessage("Testing complex numbers arithmetics.");
			// 1+0i + 0+1i = 1+1i
			f3 = f1 + f2;
			Assert::IsTrue(ComplexNumber<int>(1, 1) == f3);
			// 1+0i - 0+1i = 1+1i
			f3 = f1 - f2;
			Assert::IsTrue(ComplexNumber<int>(1, -1) == f3);
			// 1+0i * 0+1i = 1+1i
			f3 = f1 * f2;
			Assert::IsTrue(ComplexNumber<int>(0, 1) == f3);
			// 1+0i / 0+1i = 1+1i
			//f3 = f1 / f2;
			//Assert::IsTrue(ComplexNumber<int>(3) == f3);
			//// 1/2 > 1/6
			//Assert::IsTrue(f1 > f2);
			//// 1/2 > 1/6
			//Assert::IsTrue(f2 < f1);
		}
	};
}
