#include "dir.h"
#include "string_utils.h"

#include <string>

namespace WinUtils
{
	Dir::Dir(const std::string& _path)
	{
		LPCSTR s;
		auto dirPath = WinUtils::toWString(_path);
		h = FindFirstFileW(dirPath.c_str(), &data);
		path = _path;
	}

	Dir::~Dir()
	{
		if (!FindClose(h))
		{
			std::cout << "Failed To close handle" << std::endl;
		}
	}

	std::vector<WIN32_FIND_DATAW> Dir::all()
	{
		WIN32_FIND_DATAW data;
		std::vector<WIN32_FIND_DATAW> ret;

		while (FindNextFileW(h, &data) != 0)
		{
			ret.push_back(data);
		}

		return ret;
	}

	void Dir::listAll()
	{
		for (const auto& x : all())
		{
			std::cout << toString(x.cFileName) << std::endl;
		}
	}
} // WinUtils