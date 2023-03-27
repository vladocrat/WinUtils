#pragma once

#include <iostream>

namespace WinUtils
{
	std::string lastErrorAsString()
	{
		auto errorMessage = GetLastError();

		if (errorMessage == 0)
		{
			return "NO ERROR CAUGHT";
		}

		LPSTR messageBuffer = nullptr;
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			errorMessage,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&messageBuffer,
			0,
			NULL);

		std::string message(messageBuffer, size);

		if (LocalFree(messageBuffer) != NULL)
		{
			std::cout << "ERROR::FAILED_TO_FREE_STRING_BUFFER" << std::endl;
		}

		return message;
	}
} // WinUtils