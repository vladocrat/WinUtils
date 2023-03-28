#pragma once

#include "file.h"

namespace WinUtils
{
	class FileBuilder final
	{
	public:
		FileBuilder* setFilePath(const std::string&);
		FileBuilder* setSecurityAttributes(const LPSECURITY_ATTRIBUTES&);
		FileBuilder* setAccess(File::Access);
		FileBuilder* setShareMode(File::ShareMode);
		FileBuilder* setCreationDisposition(File::CreationDisposition);
		FileBuilder* setFlags(File::Flags);
		FileBuilder* setAttributes(File::Attributes);
		File build();

	private:
		File file;
	};
} // WinUtils