#include "file.h"

#include <iostream>

#include "error.h"

namespace WinUtils
{
	File::File(const std::string& filePath) : m_filePath(filePath) {}

	//File::File(const File& other)
	//{
	//	this->setFilePath(other.m_filePath);
	//	this->setAccess(other.m_access);
	//	this->setAttributes(other.m_attributes);
	//	this->setCreationDisposition(other.m_creationDisposition);
	//	this->setFlags(other.m_flags);
	//	this->setSecurityAttributes(other.m_secAttr);
	//	this->setShareMode(other.m_sharedMode);
	//	this->setWinHandle(other.m_h);
	//}

	File::File(File&& other) :
		m_h(other.m_h),
		m_filePath(other.m_filePath),
		m_secAttr(other.m_secAttr),
		m_access(other.m_access),
		m_sharedMode(other.m_sharedMode),
		m_creationDisposition(other.m_creationDisposition),
		m_flags(other.m_flags),
		m_attributes(other.m_attributes)
	{
	}

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

	bool File::readLine()
	{
		return false;
	}

	bool File::read(std::string& buffer, uint8_t byteAmount)
	{
		//update to allow overlapped struct
		return ReadFile(m_h,
			&buffer,
			byteAmount,
			NULL,
			NULL);
	}

	bool File::write(const std::string& str)
	{
		//update to allow overlapped struct
		return WriteFile(m_h,
			str.c_str(),
			str.size(),
			NULL,
			NULL);
	}

	bool File::open()
	{
		m_h = CreateFile(m_filePath.c_str(),
			m_access,
			m_sharedMode,
			m_secAttr,
			m_creationDisposition,
			flagsAndAttributes(),
			NULL);

		return isOpen();
	}
} // WinUtils
