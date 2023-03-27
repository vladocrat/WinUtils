#pragma once

#include <Windows.h>
#include <functional>

namespace WinUtils
{
	class Handle
	{
	public:
		Handle();
		Handle(HANDLE h, std::function<void()> close = {});
		~Handle();

		HANDLE* winHandle() { return &m_h; }

	private:
		HANDLE m_h = INVALID_HANDLE_VALUE;
		std::function<void()> m_closeFunc = {};
	};
} // WinUtils