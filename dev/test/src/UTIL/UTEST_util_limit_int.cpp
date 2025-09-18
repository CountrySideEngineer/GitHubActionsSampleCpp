#include "gtest/gtest.h"
#include "util.h"

TEST(UTEST_util_limit_int, 001)
{
	int value = 1;
	int min = 0;
	int max = 2;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(1, ret_val);
}

TEST(UTEST_util_limit_int, 002)
{
	int value = 0;
	int min = 0;
	int max = 2;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(0, ret_val);
}

TEST(UTEST_util_limit_int, 003)
{
	int value = 2;
	int min = 0;
	int max = 2;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(2, ret_val);
}

TEST(UTEST_util_limit_int, 004)
{
	int value = -1;
	int min = 0;
	int max = 2;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(0, ret_val);
}

TEST(UTEST_util_limit_int, 005)
{
	int value = 3;
	int min = 0;
	int max = 2;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(2, ret_val);
}

TEST(UTEST_util_limit_int, 006)
{
	int value = 3;
	int min = 0;
	int max = 0;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(0, ret_val);
}

TEST(UTEST_util_limit_int, 007)
{
	int value = 3;
	int min = 1;
	int max = 0;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(0, ret_val);
}

TEST(UTEST_util_limit_int, 008)
{
	int value = 3;
	int min = 0;
	int max = -1;

	int ret_val = limit_int(value, min, max);

	EXPECT_EQ(0, ret_val);
}
