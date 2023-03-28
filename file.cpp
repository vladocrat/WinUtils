#include "file.h"

#include <iostream>

#include "error.h"

namespace WinUtils
{
	File::File(const std::string& filePath) : m_filePath(filePath) {}

	File::~File()
	{
		if (m_h == INVALID_HANDLE_VALUE)
		{
			std::cerr << "handle is invalid" << std::endl;
			return;
		}

		if (!CloseHandle(m_h))
		{
			std::cerr << "failed to close handle: " 
				<< lastErrorAsString() << std::endl;
		}
	}

	void File::setFilePath(const std::string& filePath)
	{
		m_filePath = filePath;
	}

	void File::setWinHandle(HANDLE h)
	{
		m_h = h;
	}

	void File::setSecurityAttributes(const LPSECURITY_ATTRIBUTES& sa)
	{
		m_secAttr = sa;
	}

	void File::setAccess(Access acc)
	{
		m_access = acc;
	}

	void File::setShareMode(ShareMode sm)
	{
		m_sharedMode = sm;
	}

	void File::setCreationDisposition(CreationDisposition cd)
	{
		m_creationDisposition = cd;
	}

	void File::setFlags(Flags flags)
	{
		m_flags = flags;
	}

	void File::setAttributes(Attributes attr)
	{
		m_attributes = attr;
	}

	bool File::read()
	{
		return false;
	}

	bool File::write()
	{
		return false;
	}

	bool File::open()
	{
		return false;
	}
} // WinUtils
