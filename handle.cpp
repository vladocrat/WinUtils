#include "handle.h"

namespace WinUtils
{
	Handle::Handle() {}

	Handle::Handle(HANDLE h, std::function<void()> close = {}) 
		: m_h(h), m_closeFunc(close) {}

	Handle::~Handle()
	{
		if (m_closeFunc)
		{
			m_closeFunc();
		}
	}
} // WinUtils