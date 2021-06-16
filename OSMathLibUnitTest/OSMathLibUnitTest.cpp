#include "CppUnitTest.h"

#include "../OSMathLib/OSMathLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OSMathLibUnitTest
{
	TEST_CLASS(OSMathLibUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethodName)
		{
			Logger::WriteMessage("Testing method name.");
			Assert::AreEqual(1, 1);
		}
	};
}
