#include "stdafx.h"
#include "CppUnitTest.h"
#include <BitArray64.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitArrayTest
{		
	TEST_CLASS(BitArray64Test)
	{
	public:
		
		TEST_METHOD(SetValueTrue)
		{
			mTestHelperArray.Set(0, true);

			Assert::IsTrue(mTestHelperArray.Value(0));
		}

		TEST_METHOD(SetValueBack) 
		{
			mTestHelperArray.Set(0, true);
			mTestHelperArray.Set(0, false);

			Assert::IsFalse(mTestHelperArray.Value(1));
		}

		TEST_METHOD(SetValue) 
		{
			mTestHelperArray.Set(3, true);
			mTestHelperArray.Set(2, false);
			mTestHelperArray.Set(7, true);

			Assert::IsTrue(mTestHelperArray.Value(3));
			Assert::IsFalse(mTestHelperArray.Value(2));
			Assert::IsTrue(mTestHelperArray.Value(7));
		}

		TEST_METHOD(SetValueOutOfBounds) 
		{
			BitArray64 copyArray{ mTestHelperArray };

			mTestHelperArray.Set(BitArray64::kArraySize + 3, true);
			mTestHelperArray.Set(-25, false);

			Assert::IsTrue(copyArray == mTestHelperArray);
		}

		TEST_METHOD(ValueOutOfBounds) 
		{
			Assert::IsFalse(mTestHelperArray.Value(BitArray64::kArraySize));
			Assert::IsFalse(mTestHelperArray.Value(-1));
		}

		TEST_METHOD(Get) 
		{
			Assert::AreEqual(mTestHelperArray.Get(), 0);
			Assert::AreEqual(mTestHelperArray.Get(), 1);
		}

		TEST_METHOD(GetAfterSet) 
		{
			mTestHelperArray.Set(1, false);
			mTestHelperArray.Set(0, true); 
			
			Assert::AreEqual(mTestHelperArray.Get(), 2);
		}

		TEST_METHOD(GetWhileFragmented) 
		{
			mTestHelperArray.Set(2, true);
			mTestHelperArray.Set(0, true);

			Assert::AreEqual(mTestHelperArray.Get(), 1);
			Assert::AreEqual(mTestHelperArray.Get(), 3);
		}

		TEST_METHOD(GetWhileFull) 
		{
			for (int i{ 0 }; i < BitArray64::kArraySize; ++i) 
			{
				mTestHelperArray.Get();
			}

			Assert::AreEqual(mTestHelperArray.Get(), -1);
		}

		TEST_METHOD(Return) 
		{
			mTestHelperArray.Set(0, true);
			mTestHelperArray.Set(1, false);

			mTestHelperArray.Return(0);

			Assert::AreEqual(mTestHelperArray.Get(), 0);
			Assert::AreEqual(mTestHelperArray.Get(), 2);
		}

		TEST_METHOD(ReturnOutOfBounds) 
		{
			BitArray64 copyArray{ mTestHelperArray };
			
			mTestHelperArray.Return(-1);
			mTestHelperArray.Return(BitArray64::kArraySize);

			Assert::IsTrue(copyArray == mTestHelperArray);
		}

		TEST_METHOD(Comparison) 
		{
			BitArray64 copyArray{ mTestHelperArray };
			mTestHelperArray.Set(5, true);
			Assert::IsTrue(copyArray != mTestHelperArray);
			copyArray.Set(5, true);
			Assert::IsTrue(copyArray == mTestHelperArray);
		}

	private:
		BitArray64 mTestHelperArray;
	};
}