#include "gtest/gtest.h"
#include "util.h"

TEST(UTEST_util_init_buff, 001)
{
	const int size = 1;
	char buff[size] = { 1 };
	char val = 0;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(0, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 002)
{
	const int size = 2;
	char buff[size] = { 1, 1};
	char val = 0;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(0, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 003)
{
	const int size = 3;
	char buff[size] = { 1, 1, 1 };
	char val = 0;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(0, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 004)
{
	const int size = 1;
	char buff[size] = { 0 };
	char val = 1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(1, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 005)
{
	const int size = 2;
	char buff[size] = { 0, 0 };
	char val = 1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(1, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 006)
{
	const int size = 3;
	char buff[size] = { 0, 0, 0 };
	char val = 1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(1, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 007)
{
	const int size = 1;
	char buff[size] = { 0 };
	char val = -1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(-1, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 008)
{
	const int size = 2;
	char buff[size] = { 0, 0 };
	char val = -1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(-1, buff[i]);
	}
}

TEST(UTEST_util_init_buff, 009)
{
	const int size = 3;
	char buff[size] = { 0, 0, 0 };
	char val = -1;

	init_buff(size, buff, val);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(-1, buff[i]);
	}
}
