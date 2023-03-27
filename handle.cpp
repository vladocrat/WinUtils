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

	void Handle::setFunc(std::function<void()> f)
	{
		m_closeFunc = f;
	} 

	void Handle::setWinHandle(HANDLE h)
	{
		m_h = h;
	}

} // WinUtils