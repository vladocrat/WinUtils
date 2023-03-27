#include "handle.h"

#include <iostream>

#include "error.h"

namespace WinUtils
{
	Handle::Handle() {}

	Handle::Handle(HANDLE h, std::function<void()> close)
		: m_h(h), m_closeFunc(close) {}

	Handle::~Handle()
	{
		if (m_h == INVALID_HANDLE_VALUE)
		{
			std::cerr << "handle is invalid" << std::endl;
			return;
		}

		if (!CloseHandle(m_h))
		{
			std::cerr << "failed to close handle: " << lastErrorAsString() << std::endl;

			if (m_closeFunc)
			{
				m_closeFunc();
			}
		}

		if (m_closeFunc)
		{
			m_closeFunc();
		}
	}

	void Handle::setFunc(std::function<void()> f)
	{
		m_closeFunc = f;
	}

	void Handle::setWinHandle(HANDLE h)
	{
		m_h = h;
	}

} // WinUtils