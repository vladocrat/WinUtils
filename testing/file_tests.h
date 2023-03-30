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
	auto val = file.read(result);

	ASSERT_EQ(val, false);
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
	auto val = file.write("test");

	ASSERT_EQ(val , false);
}

TEST(FileTest, Write)
{
	auto file = FileBuilder().build();

	if (!file.open())
	{
		std::cerr << "Failed to open file" << std::endl;
		FAIL();
	}

	auto val = file.write("test");

	ASSERT_EQ(val, true);
}