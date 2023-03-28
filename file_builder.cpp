#include "file_builder.h"

namespace WinUtils
{
	FileBuilder* FileBuilder::setFilePath(const std::string& path)
	{
		file.setFilePath(path);
		return this;
	}

	FileBuilder* FileBuilder::setSecurityAttributes(const LPSECURITY_ATTRIBUTES& sa)
	{
		file.setSecurityAttributes(sa);
		return this;
	}

	FileBuilder* FileBuilder::setAccess(File::Access access)
	{
		file.setAccess(access);
		return this;
	}

	FileBuilder* FileBuilder::setShareMode(File::ShareMode sm)
	{
		file.setShareMode(sm);
		return this;
	}

	FileBuilder* FileBuilder::setCreationDisposition(File::CreationDisposition cd)
	{
		file.setCreationDisposition(cd);
		return this;
	}

	FileBuilder* FileBuilder::setFlags(File::Flags f)
	{
		file.setFlags(f);
		return this;
	}

	FileBuilder* FileBuilder::setAttributes(File::Attributes attr)
	{
		file.setAttributes(attr);
		return this;
	}

	File FileBuilder::build()
	{
		return file;
	}
} // WinUtils