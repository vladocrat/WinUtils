#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

namespace WinUtils
{
	class Dir
	{
	public:
		Dir(const std::string& _path);
		~Dir();
		
		std::vector<WIN32_FIND_DATAW> all();
		void listAll();

		bool isOpen() {return h != INVALID_HANDLE_VALUE;}
		
	private:
		std::string path;
		WIN32_FIND_DATAW data;
		HANDLE h;
	};
} // WinUtils