#include "CppUnitTest.h"

#include "../OSMathLib/fractions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace OSMathLib;

namespace OSMathLibUnitTest
{
	TEST_CLASS(OSMathLibUnitTest)
	{
	public:
		
		TEST_METHOD(TestFractionArithmatic)
		{
			fraction<int> f1 = { 1, 2 };
			fraction<int> f2 = { 1, 6 };
			fraction<int> f3;
			Logger::WriteMessage("Testing fraction arithmetics.");
			// 1/2 + 1/6 = 4/6
			f3 = f1 + f2;
			Assert::IsTrue(fraction<int>(4, 6) == f3);
			// 1/2 - 1/6 = 2/6
			f3 = f1 - f2;
			Assert::IsTrue(fraction<int>(2, 6) == f3);
			// 1/2 * 1/6 = 1/12
			f3 = f1 * f2;
			Assert::IsTrue(fraction<int>(1, 12) == f3);
			// 1/2 / 1/6 = 3/1
			f3 = f1 / f2;
			f3.reduce();
			Assert::IsTrue(fraction<int>(3) == f3);
			// 1/2 > 1/6
			Assert::IsTrue(f1 > f2);
			// 1/2 > 1/6
			Assert::IsTrue(f2 < f1);
		}
	};
}
