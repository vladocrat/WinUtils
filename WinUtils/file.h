#pragma once

#include <Windows.h>
#include <string>

namespace WinUtils
{
	class FileBuilder;

	class File final
	{
	public:
		enum Access
		{
			READ = GENERIC_READ,
			WRITE = GENERIC_WRITE,
			READWRITE = GENERIC_READ | GENERIC_WRITE
		};

		enum ShareMode
		{
			SM_NONE = 0,
			SM_DELETE = FILE_SHARE_DELETE,
			SM_READ = FILE_SHARE_READ,
			SM_WRITE = FILE_SHARE_WRITE
		};

		enum CreationDisposition
		{
			TRY_CREATE = CREATE_ALWAYS,
			TRY_NEW = CREATE_NEW,
			TRY_OPEN = OPEN_ALWAYS,
			TRY_EXISTING = OPEN_EXISTING,
			TRY_TRUNCATE_EXISTING = TRUNCATE_EXISTING
		};

		enum Flags
		{
			ARCHIVE = FILE_ATTRIBUTE_ARCHIVE,
			ENCRYPTED = FILE_ATTRIBUTE_ENCRYPTED,
			HIDDEN = FILE_ATTRIBUTE_HIDDEN,
			NORMAL = FILE_ATTRIBUTE_NORMAL,
			OFFLINE = FILE_ATTRIBUTE_OFFLINE,
			READONLY = FILE_ATTRIBUTE_READONLY,
			SYSTEM = FILE_ATTRIBUTE_SYSTEM,
			TEMPORARY = FILE_ATTRIBUTE_TEMPORARY
		};

		enum Attributes
		{
			NONE = 0,
			BACKUP_SEMANTICS = FILE_FLAG_BACKUP_SEMANTICS,
			DELETE_ON_CLOSE = FILE_FLAG_DELETE_ON_CLOSE,
			NO_BUFFERING = FILE_FLAG_NO_BUFFERING,
			OPEN_NO_RECALL = FILE_FLAG_OPEN_NO_RECALL,
			OPEN_REPARSE_POINT = FILE_FLAG_OPEN_REPARSE_POINT,
			OVERLAPPED = FILE_FLAG_OVERLAPPED,
			POSIX_SEMANTICS = FILE_FLAG_POSIX_SEMANTICS,
			RANDOM_ACCESS = FILE_FLAG_RANDOM_ACCESS,
			SESSION_AWARE = FILE_FLAG_SESSION_AWARE,
			SEQUENTIAL_SCAN = FILE_FLAG_SEQUENTIAL_SCAN,
			WRITE_THROUGH = FILE_FLAG_WRITE_THROUGH
		};

		~File();

		void setFilePath(const std::string&);
		void setWinHandle(HANDLE h);
		void setSecurityAttributes(const LPSECURITY_ATTRIBUTES&);
		void setAccess(Access);
		void setShareMode(ShareMode);
		void setCreationDisposition(CreationDisposition);
		void setFlags(Flags);
		void setAttributes(Attributes);

		bool read(std::string&, uint8_t = 0);
		bool readLine();
		bool write(const std::string&);
		bool open();

		bool isOpen() { return m_h != INVALID_HANDLE_VALUE; }

		const LPSECURITY_ATTRIBUTES secAttr()			const { return m_secAttr; }
		const HANDLE winHandle()						const { return m_h; }
		const Access access()							const { return m_access; }
		const ShareMode shareMode()						const { return m_sharedMode; }
		const CreationDisposition creationDisposition() const { return m_creationDisposition; }
		const Flags flags()								const { return m_flags; }
		const Attributes attributes()					const { return m_attributes; }
		const DWORD flagsAndAttributes()				const { return m_attributes | m_flags; }

	private:
		File() = default;
		File(const std::string&);
		File(const File&) = delete;
		File(File&&);
		File operator=(const File&) = delete;

		std::string m_filePath;
		HANDLE m_h = INVALID_HANDLE_VALUE;
		LPSECURITY_ATTRIBUTES m_secAttr = NULL;
		Access m_access = Access::READ;
		ShareMode m_sharedMode = SM_NONE;
		CreationDisposition m_creationDisposition = TRY_EXISTING;
		Flags m_flags = NORMAL;
		Attributes m_attributes = NONE;

		friend class FileBuilder;
	};
} // WinUtils