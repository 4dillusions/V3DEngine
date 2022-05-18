/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DString.h"
#include "V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"

using namespace V3D::V3DEngine::V3DMathematics;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DCore
{
	V3DString::V3DString()
	{
		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
		data[0] = NullCharacter;
	}

	V3DString::V3DString(const V3DString& value)
	{
		*this = value;
	}

	V3DString::V3DString(V3DString&& value) noexcept
	{
		*this = std::move(value);
	}

	V3DString::V3DString(bool isExplicitInstance)
	{
		if (isExplicitInstance)
			data = V3DMemory::NewArrayExplicit<char>(dataSize);
		else
			data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);

		data[0] = NullCharacter;
	}

	V3DString::V3DString(const char* text)
	{
		textLenght = GetTextLength(text);

		if (textLenght + 1 > dataSize)
			dataSize = (textLenght + 1) * 2;

		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);

		if (text == nullptr)
			data[0] = NullCharacter;
		else
		{
			for (int i = 0; i < textLenght + 1; i++)
				data[i] = text[i];

			hashCode += GetHashCode(text, textLenght, 0);
		}
	}

	V3DString::V3DString(char letter)
	{
		textLenght = 1;
		dataSize = MinDataSize;
		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);

		data[0] = letter;
		data[1] = NullCharacter;

		hashCode += GetHashCode(letter, 0);
	}

	V3DString::V3DString(int number)
	{
		*this = number;
	}

	V3DString::V3DString(float floatNumber)
	{
		*this = floatNumber;
	}

	V3DString::~V3DString()
	{
		V3DMemory::DeleteArray(data);
	}

	V3DString& V3DString::operator=(const V3DString& value)
	{
		if (this != &value)
		{
			V3DMemory::DeleteArray(data);

			textLenght = value.textLenght;
			dataSize = value.dataSize;
			hashCode = value.hashCode;

			data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
			for (int i = 0; i < textLenght + 1; i++)
				data[i] = value.data[i];
		}

		return *this;
	}

	V3DString& V3DString::operator=(V3DString&& value) noexcept
	{
		if (this != &value)
		{
			V3DMemory::DeleteArray(data);

			textLenght = value.textLenght;
			dataSize = value.dataSize;
			hashCode = value.hashCode;
			data = value.data;

			value.textLenght = 0;
			value.dataSize = MinDataSize;
			value.hashCode = 0;
			value.data = nullptr;
		}

		return *this;
	}

	V3DString& V3DString::operator=(const char* text)
	{
		V3DMemory::DeleteArray(data);

		textLenght = 0;
		dataSize = MinDataSize;
		hashCode = 0;

		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
		*this += text;

		return *this;
	}

	V3DString& V3DString::operator=(char letter)
	{
		V3DMemory::DeleteArray(data);

		textLenght = 0;
		dataSize = MinDataSize;
		hashCode = 0;

		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
		*this += letter;

		return *this;
	}

	V3DString& V3DString::operator=(int number)
	{
		V3DMemory::DeleteArray(data);

		textLenght = 0;
		dataSize = MinDataSize;
		hashCode = 0;

		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
		*this += number;

		return *this;
	}

	V3DString& V3DString::operator=(float floatNumber)
	{
		V3DMemory::DeleteArray(data);

		textLenght = 0;
		dataSize = MinDataSize;
		hashCode = 0;

		data = V3DMemory::NewArray<char>(V3DFILE_INFO, dataSize);
		*this += floatNumber;

		return *this;
	}

	V3DString V3DString::operator+(const V3DString& value) const
	{
		V3DString result(*this);
		result += value;

		return result;
	}

	V3DString V3DString::operator+(char letter) const
	{
		V3DString result(*this);
		result += letter;

		return result;
	}

	V3DString V3DString::operator+(const char* text) const
	{
		V3DString result(*this);
		result += text;

		return result;
	}

	V3DString V3DString::operator+(int number) const
	{
		V3DString result(*this);
		result += number;

		return result;
	}

	V3DString V3DString::operator+(float floatNumber) const
	{
		V3DString result(*this);
		result += floatNumber;

		return result;
	}

	V3DString& V3DString::operator+=(const V3DString& value)
	{
		const int NewTextSize = textLenght + value.textLenght + 1;
		if (dataSize < NewTextSize)
			IncrementDataSize(NewTextSize * 2);

		for (int currentIndex = textLenght, valueIndex = 0; currentIndex < NewTextSize; currentIndex++, valueIndex++)
			data[currentIndex] = value.data[valueIndex];

		hashCode += GetHashCode(value.data, value.textLenght, textLenght);
		textLenght += value.textLenght;

		return *this;
	}

	V3DString& V3DString::operator+=(const char* text)
	{
		*this += V3DString(text);
		return *this;
	}

	V3DString& V3DString::operator+=(char letter)
	{
		if (dataSize < textLenght + 1)
			IncrementDataSize();

		data[textLenght] = letter;
		data[textLenght + 1] = NullCharacter;

		hashCode += GetHashCode(letter, textLenght);
		textLenght++;

		return *this;
	}

	V3DString& V3DString::operator+=(int number)
	{
		const int NumberLenght = GetNumberLength(number);
		if (NumberLenght <= MaxNumberDigits)
		{
			const int NewTextSize = textLenght + NumberLenght + 1;
			if (dataSize < NewTextSize)
				IncrementDataSize();

			char digitsTemp[MaxNumberDigits];
			for (int i = MaxNumberDigits - 1; i > 0; i--)
			{
				if (number >= 10)
				{
					digitsTemp[i] = static_cast<char>(number % 10) + NumberToChar;  // NOLINT
					number /= 10;
				}
				else
				{
					digitsTemp[i] = static_cast<char>(number) + NumberToChar; // NOLINT
					break;
				}
			}

			char digits[MaxNumberDigits];
			for (int digitsIndex = 0, tempIndex = MaxNumberDigits - NumberLenght; digitsIndex < NumberLenght; digitsIndex++, tempIndex++)
				digits[digitsIndex] = digitsTemp[tempIndex];

			for (int currentIndex = textLenght, digitsIndex = 0; digitsIndex < NumberLenght; currentIndex++, digitsIndex++)
				data[currentIndex] = digits[digitsIndex];

			data[textLenght + NumberLenght] = NullCharacter;

			hashCode += GetHashCode(digits, NumberLenght, textLenght);
			textLenght += NumberLenght;
		}

		return *this;
	}

	V3DString& V3DString::operator+=(float floatNumber)
	{
		*this += static_cast<int>(floatNumber);
		*this += FloatNumberSplit;

		const float RightNum = floatNumber - static_cast<int>(floatNumber); // NOLINT
		int num = 0;
		for (int pow = 1; pow < MaxNumberDigits; ++pow)
		{
			num = static_cast<int>(RightNum * V3DMath::Pow(10, static_cast<float>(pow)));

			if (num % 10 == 0)
				break;
		}

		*this += num;

		return *this;
	}

	char V3DString::operator[](int index) const
	{
		return data[index];
	}

	char& V3DString::operator[](int index)
	{
		return data[index];
	}

	bool V3DString::operator<(const V3DString& value) const
	{
		return hashCode < value.hashCode;
	}

	bool V3DString::operator==(const V3DString& value) const
	{
		return hashCode == value.hashCode;
	}

	bool V3DString::operator!=(const V3DString& value) const
	{
		return hashCode != value.hashCode;
	}

	V3DString::operator int() const
	{
		return hashCode;
	}

	const char* V3DString::ToChar() const
	{
		return data;
	}

	std::wstring V3DString::ToWString() const
	{
		std::string stdText; //std::string stdText = data;
		stdText.append(data);
		std::wstring wsText;
		wsText.assign(stdText.begin(), stdText.end());
		wsText.append(L"\r\n");

		return wsText;
	}

	int V3DString::ToInt() const
	{
		int result = 0;
		int digits[MaxNumberDigits];
		int digitIndex = 0;

		while (data[digitIndex] != NullCharacter)
			if (data[digitIndex] >= '0' && data[digitIndex] <= '9' && digitIndex < MaxNumberDigits)
			{
				digits[digitIndex] = data[digitIndex] - '0';
				digitIndex++;
			}
			else
				return 0;

		for (int index = digitIndex - 1, pow = 1; index >= 0; --index, pow *= 10)
			result += digits[index] * pow;

		return result;
	}

	float V3DString::ToFloat() const
	{
		float result = 0;

		int leftCount = 0;
		int rightCount = 0;

		for (int i = 0; i < textLenght; i++)
			if (IsNumberDigit(data[i]))
				leftCount++;
			else
			{
				if (data[i] == FloatNumberSplit)
					break;

				return 0;
			}

		for (int i = leftCount + 1; i < textLenght; i++)
			if (IsNumberDigit(data[i]))
				rightCount++;
			else
				return 0;

		if (leftCount == 0 || rightCount == 0)
			return 0;

		for (int dataIndex = leftCount + 1, pow = 1; dataIndex < textLenght; dataIndex++, pow++)
			result += static_cast<float>(static_cast<int>(data[dataIndex]) - NumberToChar) / V3DMath::Pow(10, static_cast<float>(pow));

		for (int dataIndex = 0, pow = leftCount - 1; dataIndex < leftCount; dataIndex++, pow--)
			result += static_cast<float>(static_cast<int>(data[dataIndex]) - NumberToChar)* V3DMath::Pow(10, static_cast<float>(pow));

		return result;
	}

	void V3DString::IncrementDataSize(int otherDataSize)
	{
		if (otherDataSize == 0)
			this->dataSize *= 2;
		else
			this->dataSize = otherDataSize;

		const V3DString temp(*this);
		*this = temp;
	}

	int V3DString::GetHashCode(const char* text, int hashIndex)
	{
		int result = 0;

		for (int i = 0; text[i] != '\0'; i++, hashIndex++)
			result += GetHashCode(text[i], hashIndex);

		return result;
	}

	int V3DString::GetHashCode(const char* text, int lenght, int hashIndex)
	{
		int result = 0;

		for (int i = 0; i < lenght; i++, hashIndex++)
			result += GetHashCode(text[i], hashIndex);

		return result;
	}

	int V3DString::GetHashCode(char letter, int hashIndex)
	{
		return (static_cast<int>(letter) * 31 ^ hashIndex) + (7 * letter % 31 % 139);
	}

	int V3DString::GetNumberLength(int number)
	{
		int result = 1;

		while (number /= 10)
			result++;

		return result;
	}

	int V3DString::GetTextLength(const char* text)
	{
		int result = 0;

		if (text != nullptr)
			for (; text[result] != NullCharacter; result++)
				;

		return result;
	}

	bool V3DString::IsAbcLetter(char letter)
	{
		return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
	}

	bool V3DString::IsNumberDigit(char num)
	{
		return (num >= '0' && num <= '9');
	}

	void V3DString::CopyToArray(const char* text, char* textArray)
	{
		int index = 0;
		for (; text[index] != NullCharacter; index++)
			textArray[index] = text[index];

		textArray[index] = NullCharacter;
	}

	int V3DString::GetTextLength() const
	{
		return textLenght;
	}

	int V3DString::GetTextLenghtWithoutSpace() const
	{
		int result = 0;
		for (int i = 0; i < textLenght; i++)
			if (data[i] != SpaceCharacter)
				result++;

		return result;
	}

	bool V3DString::IsEmpty() const
	{
		return textLenght == 0;
	}

	int V3DString::GetDataSize() const
	{
		return dataSize;
	}

	int V3DString::GetHashCode() const
	{
		return hashCode;
	}

	bool V3DString::Contains(const V3DString& text) const
	{
		if (text.textLenght > textLenght)
			return false;

		for (int currentDataIndex = 0; currentDataIndex < textLenght; currentDataIndex++)
			if (data[currentDataIndex] == text.data[0] && (textLenght - currentDataIndex + 1 - text.textLenght) > 0)
			{
				int matchCharacterCount = 0;
				for (int dataIndex = currentDataIndex, textIndex = 0; textIndex < text.textLenght; dataIndex++, textIndex++)
					if (data[dataIndex] == text.data[textIndex])
						matchCharacterCount++;

				if (matchCharacterCount == text.textLenght)
					return true;
			}

		return false;
	}

	bool V3DString::Contains(char letter) const
	{
		for (int i = 0; i < textLenght; i++)
			if (data[i] == letter)
				return true;

		return false;
	}

	int V3DString::ContainsCount(const V3DString& text) const
	{
		int result = 0;

		if (text.textLenght > textLenght)
			return result;

		for (int currentDataIndex = 0; currentDataIndex < textLenght; currentDataIndex++)
			if (data[currentDataIndex] == text.data[0] && (textLenght - currentDataIndex + 1 - text.textLenght) > 0)
			{
				int matchCharacterCount = 0;
				for (int dataIndex = currentDataIndex, textIndex = 0; textIndex < text.textLenght; dataIndex++, textIndex++)
					if (data[dataIndex] == text.data[textIndex])
						matchCharacterCount++;

				if (matchCharacterCount == text.textLenght)
					result++;
			}

		return result;
	}

	int V3DString::ContainsCount(char letter) const
	{
		int result = 0;

		for (int i = 0; i < textLenght; i++)
			if (data[i] == letter)
				result++;

		return result;
	}

	bool V3DString::IsStartsWith(const V3DString& text) const
	{
		if (text.textLenght > textLenght)
			return false;

		for (int i = 0; i < text.textLenght; i++)
			if (data[i] != text.data[i])
				return false;

		return true;
	}

	bool V3DString::IsStartsWith(char letter) const
	{
		return data[0] == letter;
	}

	bool V3DString::IsEndsWith(const V3DString& text) const
	{
		if (text.textLenght > textLenght)
			return false;

		for (int textIndex = 0, dataIndex = textLenght - text.textLenght; textIndex < text.textLenght; textIndex++, dataIndex++)
			if (data[dataIndex] != text.data[textIndex])
				return false;

		return true;
	}

	bool V3DString::IsEndsWith(char letter) const
	{
		return data[textLenght - 1] == letter;
	}

	void V3DString::Replace(const V3DString& oldText, const V3DString& newText)
	{
		if (textLenght > 0)
		{
			int tempTextLenght = 0;
			int tempDataSize = dataSize;
			auto tempData = V3DMemory::NewArray<char>(V3DFILE_INFO, tempDataSize);

			int existCount = 0;

			for (int dataIndex = 0, tempDataIndex = 0; dataIndex < textLenght; dataIndex++, tempDataIndex++)
			{
				tempData[tempDataIndex] = data[dataIndex];
				tempTextLenght++;

				int oldTextCounter = 0;
				for (int oldTextIndex = 0, currentIndex = dataIndex; oldTextIndex < oldText.textLenght; oldTextIndex++, currentIndex++)
					if (data[currentIndex] == oldText.data[oldTextIndex])
						oldTextCounter++;

				if (oldTextCounter == oldText.textLenght)
				{
					existCount++;
					tempTextLenght--;
					dataIndex += oldText.textLenght - 1;

					for (int newTextIndex = 0; newTextIndex < newText.textLenght; newTextIndex++)
					{
						if (tempTextLenght + 1 > tempDataSize)
						{
							V3DString tempString(tempData);

							tempDataSize *= 2;
							V3DMemory::DeleteArray(tempData);
							tempData = V3DMemory::NewArray<char>(V3DFILE_INFO, tempDataSize);

							for (int i = 0; i < tempTextLenght; i++)
								tempData[i] = tempString[i];
						}

						tempData[tempDataIndex++] = newText.data[newTextIndex];
						tempTextLenght++;
					}

					tempDataIndex--;
				}
			}

			if (existCount == 0)
				V3DMemory::DeleteArray(tempData);
			else
			{
				V3DMemory::DeleteArray(data);
				data = tempData;
				dataSize = tempDataSize;

				textLenght = tempTextLenght;
				data[textLenght] = NullCharacter;
				hashCode = GetHashCode(data, textLenght, 0);
			}
		}
	}

	void V3DString::Replace(char oldLetter, char newLetter)
	{
		if (textLenght > 0)
			for (int dataIndex = 0; dataIndex < textLenght; dataIndex++)
				if (data[dataIndex] == oldLetter)
				{
					hashCode -= GetHashCode(oldLetter, dataIndex);
					data[dataIndex] = newLetter;
					hashCode += GetHashCode(newLetter, dataIndex);
				}
	}

	void V3DString::Replace(char letter, int index)
	{
		if (textLenght > index)
		{
			hashCode -= GetHashCode(data[index], index);
			data[index] = letter;
			hashCode += GetHashCode(letter, index);
		}
	}

	void V3DString::Replace(int number, int digits)
	{
		Clear();

		if (digits <= MaxNumberDigits)
		{
			const int NumberLenght = GetNumberLength(number);

			if (NumberLenght < digits)
				for (int i = 0; i < (digits - NumberLenght); ++i)
				{
					data[textLenght] = '0';
					hashCode += GetHashCode('0', textLenght++);
				}

			*this += number;
		}
	}

	void V3DString::Remove(int startIndex, int count)
	{
		if (startIndex + count <= textLenght)
		{
			const auto TempText = V3DMemory::NewArray<char>(V3DFILE_INFO, textLenght + 1);

			int tempIndex = 0;
			for (int dataIndex = 0; dataIndex < startIndex; tempIndex++, dataIndex++)
				TempText[tempIndex] = data[dataIndex];

			for (int dataIndex = startIndex + count; dataIndex < textLenght + 1; tempIndex++, dataIndex++)
				TempText[tempIndex] = data[dataIndex];

			V3DMemory::DeleteArray(data);
			data = TempText;
			textLenght -= count;
			hashCode = GetHashCode(data, textLenght, 0);
		}
	}

	void V3DString::Remove(const V3DString& text)
	{
		if (text.textLenght <= textLenght)
		{
			const auto TempText = V3DMemory::NewArray<char>(V3DFILE_INFO, textLenght + 1);

			int tempIndex = 0;
			for (int dataIndex = 0; dataIndex < textLenght + 1; dataIndex++)
			{
				TempText[tempIndex++] = data[dataIndex];

				bool isExist = true;
				for (int i = 0; i < text.textLenght; i++)
					if (data[dataIndex + i] != text.data[i])
					{
						isExist = false;
						break;
					}

				if (isExist)
				{
					tempIndex--;
					dataIndex += (text.textLenght - 1);
				}
			}

			V3DMemory::DeleteArray(data);
			data = TempText;
			textLenght = tempIndex - 1;
			hashCode = GetHashCode(data, textLenght, 0);
		}
	}

	void V3DString::Remove(char Letter)
	{
		if (textLenght > 0)
		{
			const auto TempText = V3DMemory::NewArray<char>(V3DFILE_INFO, textLenght + 1);

			int tempIndex = 0;
			for (int dataIndex = 0; dataIndex < textLenght + 1; dataIndex++)
				if (data[dataIndex] != Letter)
					TempText[tempIndex++] = data[dataIndex];

			V3DMemory::DeleteArray(data);
			data = TempText;
			textLenght = tempIndex - 1;
			hashCode = GetHashCode(data, textLenght, 0);
		}
	}

	void V3DString::Trim()
	{
		/*
			White space characters
			' ' (0x20) space(SPC)
			'\t' (0x09) horizontal tab(TAB)
			'\n' (0x0a) newline(LF)
			'\v' (0x0b) vertical tab(VT)
			'\f' (0x0c) feed(FF)
			'\r' (0x0d) carriage return (CR)
		*/
		constexpr char whiteSpaceCharacters[] = " \t\n\v\f\r";
		const auto TempText = V3DMemory::NewArray<char>(V3DFILE_INFO, textLenght + 1);

		int newTextLenght = 0;
		for (int tempIndex = 0, dataIndex = 0; dataIndex < textLenght + 1; dataIndex++)
		{
			bool isWhiteCpaceCharacter = false;
			for (unsigned int i = 0; i < sizeof(whiteSpaceCharacters) - 1; i++)
				if (data[dataIndex] == whiteSpaceCharacters[i])
				{
					isWhiteCpaceCharacter = true;
					break;
				}

			if (!isWhiteCpaceCharacter)
			{
				TempText[tempIndex++] = data[dataIndex];
				newTextLenght++;
			}
		}

		textLenght = newTextLenght - 1;

		V3DMemory::DeleteArray(data);
		data = TempText;
		hashCode = GetHashCode(data, textLenght, 0);
	}

	void V3DString::Clear()
	{
		data[0] = NullCharacter;
		textLenght = 0;
		hashCode = 0;
	}

	V3DDynamicArray<V3DString> V3DString::Split(char separator) const
	{
		V3DDynamicArray<V3DString> result;

		if (textLenght > 0)
		{
			V3DString temp;
			for (int i = 0; i < textLenght + 1; i++)
			{
				if (data[i] == separator || i == textLenght)
				{
					result.Add(temp);
					temp.Clear();

					continue;
				}

				temp += data[i];
			}
		}

		return result;
	}

	V3DDynamicArray<V3DString> V3DString::Split(const V3DString& text) const
	{
		V3DString temp(*this);
		temp.Replace(text, V3DString("~"));

		return temp.Split('~');
	}
}
