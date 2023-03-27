#pragma once

#include <iostream>
#include <codecvt>

namespace WinUtils
{
	std::wstring toWString(const std::string& str)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		return converter.from_bytes(str);
	}

	// data lost if non-ASCII
	std::string toString(const std::wstring& str)
	{
		return std::string(str.begin(), str.end());
	}
} // WinUtils