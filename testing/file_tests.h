#include <gtest/gtest.h>
#include <iostream>

#include "WinUtils/file_builder.h"
#include "WinUtils/error.h"

using namespace WinUtils;

TEST(FileTest, ConfigurationWithoutFilePath)
{
	auto file = FileBuilder()
		.build();

	ASSERT_TRUE(!file.open());
}

TEST(FileTest, Configuration)
{
	auto file = FileBuilder()
		.setFilePath("readbytes_test.txt")
		.build();

	ASSERT_TRUE(file.open());
}

TEST(FileTest, ReadWithoutConfiguration)
{
	auto file = FileBuilder().build();
	std::string result;

	ASSERT_TRUE(!file.read(result));
}

TEST(FileTest, ReadBytes)
{
	auto file = FileBuilder()
		.setFilePath("readbytes_test.txt")
		.build();

	if (!file.open())
	{
		std::cerr << "failed to open file: " << lastErrorAsString() << std::endl;
		FAIL();
	}

	std::string result;

	if (!file.read(result, 4))
	{
		std::cerr << "failed to read: " << lastErrorAsString() << std::endl;
		FAIL();
	}

	ASSERT_EQ(result, "test");
}

TEST(FileTest, WriteWithoutConfiguration)
{
	auto file = FileBuilder().build();

	ASSERT_TRUE(!file.write("test"));
}

TEST(FileTest, Write)
{
	auto file = FileBuilder()
		.setCreationDisposition(File::TRY_CREATE)
		.setFilePath("write_test.txt")
		.setAccess(File::WRITE)
		.build();

	if (!file.open())
	{
		std::cerr << "Failed to open file: " << lastErrorAsString() << std::endl;
		FAIL();
	}

	auto ok = file.write("test");

	if (!ok)
	{
		std::cerr << "Failed to write to file: " << lastErrorAsString() << std::endl;
		FAIL();
	}

	SUCCEED();
}

TEST(FileTest, WriteWithoutAccess)
{
	auto file = FileBuilder()
		.setCreationDisposition(File::TRY_CREATE)
		.setFilePath("write_test.txt")
		.build();

	if (!file.open())
	{
		std::cerr << "Failed to open file: " << lastErrorAsString() << std::endl;
		FAIL();
	}

	ASSERT_TRUE(!file.write("test"));
}

