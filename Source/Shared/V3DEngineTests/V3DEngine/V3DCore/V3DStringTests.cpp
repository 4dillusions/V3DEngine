/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStringTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DStringTests::CtorOperatorsTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DString txt("test");
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1, V3DFILE_INFO);
		txt.~V3DString();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		
		constexpr auto StringTestCtorOperators = []()
		{
			const V3DString Text("test123");

			V3DString text2("test");
			text2 += "123";

			V3DString text3;
			text3 += "test";
			text3 += "123";

			V3DString text4("test");
			text4 += 123;

			V3DString text5;
			text5 += "test";
			text5 += 123;

			V3DString text6(text5);

			V3DTest::AssertOk(Text == text2, V3DFILE_INFO);
			V3DTest::AssertOk(Text == text3, V3DFILE_INFO);
			V3DTest::AssertOk(Text == text4, V3DFILE_INFO);
			V3DTest::AssertOk(Text == text5, V3DFILE_INFO);
			V3DTest::AssertOk(Text == text6, V3DFILE_INFO);

			text6 += 'K';
			text6 += 3.14f;

			V3DTest::AssertOk(text6 == V3DString("test123K3.140"), V3DFILE_INFO);

			text6.Clear();
			text6 = V3DString("test") + 123 + 'K' + 3.14f + " hoho";
			V3DTest::AssertOk(text6 == V3DString("test123K3.140 hoho"), V3DFILE_INFO);

			text6 = 3.14f;
			V3DTest::AssertOk(text6 == V3DString("3.140"), V3DFILE_INFO);
		};
		StringTestCtorOperators();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::ReturnTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestReturn = []()
		{
			V3DString result("hoho");

			return result;
		};
		V3DTest::AssertOk(StringTestReturn() == V3DString("hoho"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::ToTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestTo = []()
		{
			V3DString text;

			text = 148248853;
			V3DTest::AssertOk(148248853 == text.ToInt(), V3DFILE_INFO);

			text += "hoho";
			V3DTest::AssertOk(0 == text.ToInt(), V3DFILE_INFO);

			text = 3.1482488038f;
			V3DTest::AssertOk(V3DMath::IsEqual(3.1482488038f, text.ToFloat()), V3DFILE_INFO);
			V3DTest::AssertOk(0 == text.ToInt(), V3DFILE_INFO);
		};
		StringTestTo();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::HashAndConversionTest()
	{
		const char* Ctext1 = "appletree123";
		const char* Ctext2 = "appletree123";
		constexpr char Ctext3[20] = "appletree124";

		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1) == V3DString::GetHashCode(Ctext2), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1) != V3DString::GetHashCode(Ctext3), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString("appletree123") == V3DString(Ctext2), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString("appletree124").GetHashCode() == V3DString::GetHashCode(Ctext3), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString("appletree124") == V3DString(Ctext3), V3DFILE_INFO);

		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1, 12, 2) == V3DString::GetHashCode(Ctext2, 12, 2), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1, 12, 2) != V3DString::GetHashCode(Ctext3, 12, 2), V3DFILE_INFO);

		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1[11], 0) == V3DString::GetHashCode(Ctext2[11], 0), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(Ctext1[11], 0) != V3DString::GetHashCode(Ctext3[11], 0), V3DFILE_INFO);

		const auto Five = V3DString("five").GetHashCode();
		const auto Nine = V3DString("nine").GetHashCode();
		const auto Nini = V3DString("nini").GetHashCode();
		const auto Inin = V3DString("inin").GetHashCode();
		V3DTest::AssertOk(Five != Nine, V3DFILE_INFO);
		V3DTest::AssertOk(Nini != Inin, V3DFILE_INFO);
	}
	
	void V3DStringTests::GetTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestGet = []()
		{
			V3DTest::AssertOk(8 == V3DString::GetNumberLength(12345678), V3DFILE_INFO);

			const char* GoodAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
			const char* WrongAlphabet = "abcd}";
			const char* WrongAlphabet2 = "abcd0";

			bool isGoodAlphabet = true;
			for (int index = 0; GoodAlphabet[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(GoodAlphabet[index]))
				{
					isGoodAlphabet = false;
					break;
				}
			}
			V3DTest::AssertOk(isGoodAlphabet, V3DFILE_INFO);

			bool isWrongAlphabet = true;
			for (int index = 0; WrongAlphabet[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(WrongAlphabet[index]))
				{
					isWrongAlphabet = false;
					break;
				}
			}
			V3DTest::AssertOk(isWrongAlphabet == false, V3DFILE_INFO);

			bool isWrongAlphabet2 = true;
			for (int index = 0; WrongAlphabet2[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(WrongAlphabet2[index]))
				{
					isWrongAlphabet2 = false;
					break;
				}
			}
			V3DTest::AssertOk(isWrongAlphabet2 == false, V3DFILE_INFO);

			bool isDigitChecker = true;
			for (int i = 0; i < 256; i++)
			{
				if (i < 10)
				{
					if (!V3DString::IsNumberDigit(static_cast<char>(i + '0')))
					{
						isDigitChecker = false;
						break;
					}
				}
				else if (V3DString::IsNumberDigit(static_cast<char>(i + '0')))
				{
					isDigitChecker = false;
					break;
				}
			}
			V3DTest::AssertOk(isDigitChecker, V3DFILE_INFO);

			const V3DString Text("test 123  ");
			V3DTest::AssertOk(Text.GetTextLength() == 10, V3DFILE_INFO);
			V3DTest::AssertOk(Text.GetTextLenghtWithoutSpace() == 7, V3DFILE_INFO);

			V3DString empty;

			V3DTest::AssertOk(empty.IsEmpty(), V3DFILE_INFO);
			V3DTest::AssertOk(empty == V3DString(""), V3DFILE_INFO);

			const V3DString Empty2("");
			V3DTest::AssertOk(Empty2.IsEmpty(), V3DFILE_INFO);

			empty += "hohoh";
			V3DTest::AssertOk(!empty.IsEmpty(), V3DFILE_INFO);

			empty.Clear();
			V3DTest::AssertOk(empty.IsEmpty(), V3DFILE_INFO);

			empty += 'h';
			V3DTest::AssertOk(!empty.IsEmpty(), V3DFILE_INFO);
		};
		StringTestGet();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::IsTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestIs = []()
		{
			const V3DString Example("X-Ample123_123B");
			const V3DString Example2("arvizturo tukorfurogep");

			V3DTest::AssertOk(Example.Contains(V3DString("X-Ample123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("X-Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("X-Am")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("e12")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("23")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("3B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("X-Ample124")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("1234")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(Example.Contains(V3DString("X-ample123")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString("o ")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString("or")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString("og")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString("roe")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString("ogepp")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(Example.Contains(V3DString('_')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString('o')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString(' ')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example2.Contains(V3DString('x')) == false, V3DFILE_INFO);

			V3DTest::AssertOk(2 == Example2.ContainsCount(V3DString("tu")), V3DFILE_INFO);
			V3DTest::AssertOk(1 == Example2.ContainsCount(V3DString("o t")), V3DFILE_INFO);

			V3DTest::AssertOk(3 == Example2.ContainsCount(V3DString('o')), V3DFILE_INFO);
			V3DTest::AssertOk(1 == Example2.ContainsCount(V3DString(' ')), V3DFILE_INFO);
			V3DTest::AssertOk(3 == Example2.ContainsCount(V3DString('u')), V3DFILE_INFO);

			V3DTest::AssertOk(Example.IsStartsWith(V3DString("X-Ample123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsStartsWith(V3DString("X-Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsStartsWith(V3DString("X-Am")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsStartsWith(V3DString("Ample")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(Example.IsStartsWith(V3DString('X')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsStartsWith(V3DString('-')) == false, V3DFILE_INFO);

			V3DTest::AssertOk(Example.IsEndsWith(V3DString("123_123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsEndsWith(V3DString("_123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsEndsWith(V3DString("123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsEndsWith(V3DString("1234")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(Example.IsEndsWith(V3DString('B')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(Example.IsEndsWith(V3DString('b')) == false, V3DFILE_INFO);
		};
		StringTestIs();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::CopyArrayTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestCopyArray = []()
		{
			char text[20];
			V3DString::CopyToArray("hello123", text);
			V3DTest::AssertOk(V3DString(text) == V3DString("hello123"), V3DFILE_INFO);
		};
		StringTestCopyArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::ReplaceRemoveTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestReplaceRemove = []()
		{
			V3DString text("X-Ample123_123B");

			text.Replace(V3DString("X-"), V3DString("Y+"));
			V3DTest::AssertOk(text == V3DString("Y+Ample123_123B"), V3DFILE_INFO);
			text.Replace(V3DString("X"), V3DString("Z"));
			V3DTest::AssertOk(text == V3DString("Y+Ample123_123B"), V3DFILE_INFO);

			text.Replace('1', '2');
			V3DTest::AssertOk(text == V3DString("Y+Ample223_223B"), V3DFILE_INFO);
			text.Replace('1', '3');
			V3DTest::AssertOk(text == V3DString("Y+Ample223_223B"), V3DFILE_INFO);
			text.Replace('+', ':');
			V3DTest::AssertOk(text == V3DString("Y:Ample223_223B"), V3DFILE_INFO);

			text.Replace('4', 1);
			V3DTest::AssertOk(text == V3DString("Y4Ample223_223B"), V3DFILE_INFO);

			text.Replace(123, 5);
			V3DTest::AssertOk(text == V3DString("00123"), V3DFILE_INFO);

			text = "X-Ample123_123B";

			text.Remove(10, 5);
			V3DTest::AssertOk(text == V3DString("X-Ample123"), V3DFILE_INFO);

			text.Remove(V3DString(123));
			V3DTest::AssertOk(text == V3DString("X-Ample"), V3DFILE_INFO);

			text = "arvizturo tukorfurogep";
			text.Remove('o');
			V3DTest::AssertOk(text == V3DString("arviztur tukrfurgep"), V3DFILE_INFO);

			text.Trim();
			V3DTest::AssertOk(text == V3DString("arvizturtukrfurgep"), V3DFILE_INFO);

			text.Clear();
			V3DTest::AssertOk(text == V3DString(""), V3DFILE_INFO);
		};
		StringTestReplaceRemove();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::LargeTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestLarge = []()
		{
			V3DString text;
			constexpr int TextSize = 1200;

			char largeText[TextSize];
			for (int index = 0; index < TextSize - 1; index++)
				largeText[index] = 'A';
			largeText[TextSize - 1] = '\0';

			text = largeText;
			V3DTest::AssertOk(TextSize - 1 == text.GetTextLength(), V3DFILE_INFO);
			V3DTest::AssertOk(TextSize * 2 == text.GetDataSize(), V3DFILE_INFO);

			text += "hoho";
			V3DTest::AssertOk(text.IsEndsWith(V3DString("hoho")), V3DFILE_INFO);

			text += largeText;
			V3DTest::AssertOk((TextSize * 4) + ((V3DString::GetTextLength("hoho") - 1) * 2) == text.GetDataSize(), V3DFILE_INFO);
		};
		StringTestLarge();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::CopyTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto StringTestCopy = []() { return V3DString("hoho1234!"); };
		V3DTest::AssertOk(StringTestCopy() == V3DString("hoho1234!"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStringTests::SplitTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		auto StringTestSplit = []()
		{
			V3DString text;

			text = "one#two#three#four";
			auto numbers = text.Split('#');
			V3DTest::AssertOk(*numbers[0] == V3DString("one"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[1] == V3DString("two"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[2] == V3DString("three"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[3] == V3DString("four"), V3DFILE_INFO);
		};
		StringTestSplit();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		auto StringTestSplit2 = []()
		{
			V3DString text;

			text = "onesplittwosplitthreesplitfour";
			auto numbers = text.Split(V3DString("split"));
			V3DTest::AssertOk(*numbers[0] == V3DString("one"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[1] == V3DString("two"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[2] == V3DString("three"), V3DFILE_INFO);
			V3DTest::AssertOk(*numbers[3] == V3DString("four"), V3DFILE_INFO);
		};
		StringTestSplit2();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		auto StringTestSplit3 = []()
		{
			const V3DString Text;
			const auto Empty = Text.Split(V3DString('#'));
			V3DTest::AssertOk(Empty.GetLength() == 0, V3DFILE_INFO);

			const V3DString Text2("#");
			auto empty2 = Text2.Split(V3DString('#'));
			V3DTest::AssertOk(empty2[0]->IsEmpty(), V3DFILE_INFO);
		};
		StringTestSplit3();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DStringTests::RunAllTests()
	{	
		CtorOperatorsTest();
		ReturnTest();
		ToTest();
		HashAndConversionTest();
		GetTest();
		IsTest();
		CopyArrayTest();
		ReplaceRemoveTest();
		LargeTest();
		CopyTest();
		SplitTest();
	}
}
