/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DDynamicArray.h"

#include <string>

namespace V3D::V3DEngine::V3DCore
{
	/*
		Basic string object for platform-independent fast using
		note: Clear and operator+= functions are realatively fast operations for string building
	*/
	class V3DENGINE_API V3DString final
	{
        static const char NullCharacter = '\0';
        static const char FloatNumberSplit = '.';
        static const char SpaceCharacter = ' ';

        static const int MinDataSize = 512;
        static const int MaxNumberDigits = 10;
        static const int NumberToChar = 48;

        int dataSize = MinDataSize;
        char* data{};
        int textLenght{};
        int hashCode{};

    public:
        V3DString();

        V3DString(const V3DString& value);
        V3DString(V3DString&& value) noexcept;

        explicit V3DString(const char* text);
        explicit V3DString(char letter);
        explicit V3DString(int number);
        explicit V3DString(float floatNumber);

        ~V3DString();

        V3DString& operator=(const V3DString& value);
        V3DString& operator=(V3DString&& value) noexcept;

        V3DString& operator=(const char* text);
        V3DString& operator=(char letter);
        V3DString& operator=(int number);
        V3DString& operator=(float floatNumber);

        V3DString operator+(const V3DString& value) const;
        V3DString operator+(char letter) const;
        V3DString operator+(const char* text) const;
        V3DString operator+(int number) const;
        V3DString operator+(float floatNumber) const;

        V3DString& operator+=(const V3DString& value);
        V3DString& operator+=(const char* text);
        V3DString& operator+=(char letter);
        V3DString& operator+=(int number);
        V3DString& operator+=(float floatNumber);

        char operator[](int index) const; //char c = text[0];
        char& operator[](int index); //text[0] = 'A';

        bool operator<(const V3DString& value) const;
        bool operator==(const V3DString& value) const;
        bool operator!=(const V3DString& value) const;

        explicit operator int() const; //hash code

        [[nodiscard]] const char* ToChar() const;
        [[nodiscard]] std::wstring ToWString() const;
        [[nodiscard]] int ToInt() const;
        [[nodiscard]] float ToFloat() const;

    private:
        void IncrementDataSize(int dataSize = 0);

    public:
        static int GetHashCode(const char* text, int hashIndex = 0);
        static int GetHashCode(const char* text, int lenght, int hashIndex);
        static int GetHashCode(char letter, int hashIndex);
        static int GetNumberLength(int number);
        static int GetTextLength(const char* text);
        static bool IsAbcLetter(char letter);
        static bool IsNumberDigit(char num);
        static void CopyToArray(const char* text, char* textArray);

        [[nodiscard]] int GetTextLength() const;
        [[nodiscard]] int GetTextLenghtWithoutSpace() const;
        [[nodiscard]] bool IsEmpty() const;
        [[nodiscard]] int GetDataSize() const;
        [[nodiscard]] int GetHashCode() const;

        [[nodiscard]] bool Contains(const V3DString& text) const;
        [[nodiscard]] bool Contains(char letter) const;
        [[nodiscard]] int ContainsCount(const V3DString& text) const;
        [[nodiscard]] int ContainsCount(char letter) const;
        [[nodiscard]] bool IsStartsWith(const V3DString& text) const;
        [[nodiscard]] bool IsStartsWith(char letter) const;
        [[nodiscard]] bool IsEndsWith(const V3DString& text) const;
        [[nodiscard]] bool IsEndsWith(char letter) const;

        void Replace(const V3DString& oldText, const V3DString& newText);
        void Replace(char oldLetter, char newLetter);
        void Replace(char letter, int index);
        void Replace(int number, int digits); //s.ReplaceToLcdNumber(3, 4) => 0003
        void Remove(int startIndex, int count);
        void Remove(const V3DString& text);
        void Remove(char Letter);
        void Trim();
        void Clear();

        [[nodiscard]] V3DCollections::V3DDynamicArray<V3DString> Split(char separator) const;
        [[nodiscard]] V3DCollections::V3DDynamicArray<V3DString> Split(const V3DString& text) const;
	};
}
