/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStringTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DStringTest::CtorOperatorsTest()
	{
		const auto StringTestCtorOperators = []()
		{
			const V3DString text("test123");

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

			V3DTest::AssertOk(text == text2, V3DFILE_INFO);
			V3DTest::AssertOk(text == text3, V3DFILE_INFO);
			V3DTest::AssertOk(text == text4, V3DFILE_INFO);
			V3DTest::AssertOk(text == text5, V3DFILE_INFO);
			V3DTest::AssertOk(text == text6, V3DFILE_INFO);

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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::ReturnTest()
	{
		const auto StringTestReturn = []()
		{
			V3DString result("hoho");

			return result;
		};
		V3DTest::AssertOk(StringTestReturn() == V3DString("hoho"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::ToTest()
	{
		const auto StringTestTo = []()
		{
			V3DString text;

			text = 148248853;
			V3DTest::AssertOk(148248853 == text.ToInt(), V3DFILE_INFO);

			text += "hoho";
			V3DTest::AssertOk(0 == text.ToInt(), V3DFILE_INFO);

			text = 3.1482488038f;
			V3DTest::AssertOk(3.1482488038f == text.ToFloat(), V3DFILE_INFO);
			V3DTest::AssertOk(0 == text.ToInt(), V3DFILE_INFO);
		};
		StringTestTo();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::GetHashTest()
	{
		const char* ctext1 = "appletree123";
		const char* ctext2 = "appletree123";
		const char* ctext3 = "appletree124";

		V3DTest::AssertOk(V3DString::GetHashCode(ctext1) == V3DString::GetHashCode(ctext2), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(ctext1) != V3DString::GetHashCode(ctext3), V3DFILE_INFO);

		V3DTest::AssertOk(V3DString::GetHashCode(ctext1, 12, 2) == V3DString::GetHashCode(ctext2, 12, 2), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(ctext1, 12, 2) != V3DString::GetHashCode(ctext3, 12, 2), V3DFILE_INFO);

		V3DTest::AssertOk(V3DString::GetHashCode(ctext1[11], 0) == V3DString::GetHashCode(ctext2[11], 0), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString::GetHashCode(ctext1[11], 0) != V3DString::GetHashCode(ctext3[11], 0), V3DFILE_INFO);
	}
	
	void V3DStringTest::GetTest()
	{
		const auto StringTestGet = []()
		{
			V3DTest::AssertOk(8 == V3DString::GetNumberLength(12345678), V3DFILE_INFO);

			const char* goodAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
			const char* wrongAlphabet = "abcd}";
			const char* wrongAlphabet2 = "abcd0";

			bool isGoodAlphabet = true;
			for (int index = 0; goodAlphabet[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(goodAlphabet[index]))
				{
					isGoodAlphabet = false;
					break;
				}
			}
			V3DTest::AssertOk(isGoodAlphabet, V3DFILE_INFO);

			bool isWrongAlphabet = true;
			for (int index = 0; wrongAlphabet[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(wrongAlphabet[index]))
				{
					isWrongAlphabet = false;
					break;
				}
			}
			V3DTest::AssertOk(isWrongAlphabet == false, V3DFILE_INFO);

			bool isWrongAlphabet2 = true;
			for (int index = 0; wrongAlphabet2[index] != 0; index++)
			{
				if (!V3DString::IsAbcLetter(wrongAlphabet2[index]))
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

			const V3DString text("test 123  ");
			V3DTest::AssertOk(text.GetTextLength() == 10, V3DFILE_INFO);
			V3DTest::AssertOk(text.GetTextLenghtWithoutSpace() == 7, V3DFILE_INFO);

			V3DString empty;

			V3DTest::AssertOk(empty.IsEmpty(), V3DFILE_INFO);
			V3DTest::AssertOk(empty == V3DString(""), V3DFILE_INFO);

			const V3DString empty2("");
			V3DTest::AssertOk(empty2.IsEmpty(), V3DFILE_INFO);

			empty += "hohoh";
			V3DTest::AssertOk(!empty.IsEmpty(), V3DFILE_INFO);

			empty.Clear();
			V3DTest::AssertOk(empty.IsEmpty(), V3DFILE_INFO);

			empty += 'h';
			V3DTest::AssertOk(!empty.IsEmpty(), V3DFILE_INFO);
		};
		StringTestGet();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::IsTest()
	{
		const auto StringTestIs = []()
		{
			const V3DString example("X-Ample123_123B");
			const V3DString example2("arvizturo tukorfurogep");

			V3DTest::AssertOk(example.Contains(V3DString("X-Ample123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("X-Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("X-Am")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("e12")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("23")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("3B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("X-Ample124")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("1234")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(example.Contains(V3DString("X-ample123")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString("o ")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString("or")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString("og")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString("roe")) == false, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString("ogepp")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(example.Contains(V3DString('_')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString('o')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString(' ')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example2.Contains(V3DString('x')) == false, V3DFILE_INFO);

			V3DTest::AssertOk(2 == example2.ContainsCount(V3DString("tu")), V3DFILE_INFO);
			V3DTest::AssertOk(1 == example2.ContainsCount(V3DString("o t")), V3DFILE_INFO);

			V3DTest::AssertOk(3 == example2.ContainsCount(V3DString('o')), V3DFILE_INFO);
			V3DTest::AssertOk(1 == example2.ContainsCount(V3DString(' ')), V3DFILE_INFO);
			V3DTest::AssertOk(3 == example2.ContainsCount(V3DString('u')), V3DFILE_INFO);

			V3DTest::AssertOk(example.IsStartsWith(V3DString("X-Ample123")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsStartsWith(V3DString("X-Ample")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsStartsWith(V3DString("X-Am")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsStartsWith(V3DString("Ample")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(example.IsStartsWith(V3DString('X')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsStartsWith(V3DString('-')) == false, V3DFILE_INFO);

			V3DTest::AssertOk(example.IsEndsWith(V3DString("123_123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsEndsWith(V3DString("_123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsEndsWith(V3DString("123B")) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsEndsWith(V3DString("1234")) == false, V3DFILE_INFO);

			V3DTest::AssertOk(example.IsEndsWith(V3DString('B')) == true, V3DFILE_INFO);
			V3DTest::AssertOk(example.IsEndsWith(V3DString('b')) == false, V3DFILE_INFO);
		};
		StringTestIs();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::CopyArrayTest()
	{
		const auto StringTestCopyArray = []()
		{
			char text[20];
			V3DString::CopyToArray("hello123", text);
			V3DTest::AssertOk(V3DString(text) == V3DString("hello123"), V3DFILE_INFO);
		};
		StringTestCopyArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::ReplaceRemoveTest()
	{
		const auto StringTestReplaceRemove = []()
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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::LargeTest()
	{
		const auto StringTestLarge = []()
		{
			V3DString text;
			const int textSize = 1200;

			char largeText[textSize];
			for (int index = 0; index < textSize - 1; index++)
				largeText[index] = 'A';
			largeText[textSize - 1] = '\0';

			text = largeText;
			V3DTest::AssertOk(textSize - 1 == text.GetTextLength(), V3DFILE_INFO);
			V3DTest::AssertOk(textSize * 2 == text.GetDataSize(), V3DFILE_INFO);

			text += "hoho";
			V3DTest::AssertOk(text.IsEndsWith(V3DString("hoho")), V3DFILE_INFO);

			text += largeText;
			V3DTest::AssertOk((textSize * 4) + ((V3DString::GetTextLength("hoho") - 1) * 2) == text.GetDataSize(), V3DFILE_INFO);
		};
		StringTestLarge();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::CopyTest()
	{
		const auto StringTestCopy = []() { return V3DString("hoho1234!"); };
		V3DTest::AssertOk(StringTestCopy() == V3DString("hoho1234!"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DStringTest::SplitTest()
	{
		/*auto StringTestSplit = []()
		{
			V3DString text;

			text = "one#two#three#four";
			auto numbers = text.Split('#');
			V3DTest::AssertOk(numbers[0] == V3DString("one"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[1] == V3DString("two"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[2] == V3DString("three"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[3] == V3DString("four"), V3DFILE_INFO);
		};
		StringTestSplit();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		auto StringTestSplit2 = []()
		{
			V3DString text;

			text = "onesplittwosplitthreesplitfour";
			auto numbers = text.Split(V3DString("split"));
			V3DTest::AssertOk(numbers[0] == V3DString("one"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[1] == V3DString("two"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[2] == V3DString("three"), V3DFILE_INFO);
			V3DTest::AssertOk(numbers[3] == V3DString("four"), V3DFILE_INFO);
		};
		StringTestSplit2();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		auto StringTestSplit3 = []()
		{
			V3DString text;
			auto empty = text.Split(V3DString('#'));
			V3DTest::AssertOk(empty.GetLength() == 0, V3DFILE_INFO);

			V3DString text2("#");
			auto empty2 = text2.Split(V3DString('#'));
			V3DTest::AssertOk(empty2[0].IsEmpty(), V3DFILE_INFO);
		};
		StringTestSplit3();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);*/
	}

	void V3DStringTest::RunAllTests()
	{	
		CtorOperatorsTest();
		ReturnTest();
		ToTest();
		GetHashTest();
		GetTest();
		IsTest();
		CopyArrayTest();
		ReplaceRemoveTest();
		LargeTest();
		CopyTest();
		SplitTest();
	}
}
