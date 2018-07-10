#include <gtest/gtest.h>
#include <tchar.h>


TEST(SquareRootTest, ZeroAndNegativeNos) {
	ASSERT_EQ(0.0, ::sqrt(0.0));
//	ASSERT_EQ(NANf, ::sqrt(-22.0));
}

int _tmain(int argc, TCHAR **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
