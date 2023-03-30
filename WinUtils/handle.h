#pragma once

#include <Windows.h>
#include <functional>

namespace WinUtils
{
	class Handle final
	{
	public:
		Handle();
		Handle(HANDLE h, const std::function<void()>& close = {});
		Handle(const Handle&) = delete;
		Handle(Handle&&) = delete;
		Handle operator=(const Handle&) = delete;
		~Handle();

		void setFunc(const std::function<void()>&);
		void setWinHandle(HANDLE h);

		[[nodiscard]] bool ok() { return m_h != INVALID_HANDLE_VALUE; }
		const HANDLE winHandle() const { return m_h; }

	private:
		HANDLE m_h = INVALID_HANDLE_VALUE;
		std::function<void()> m_closeFunc = {};
	};
} // WinUtils