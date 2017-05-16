#include "server.h"

#include "gtest/gtest.h"


TEST(CreateServerTest, InitAndCleanup) {
	auto s = udp::server(6669, 512);

	EXPECT_EQ(true, s.init());
	EXPECT_EQ(true, s.cleanup());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
