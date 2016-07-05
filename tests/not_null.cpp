#include <gtest/gtest.h>
#include <not_null.h>

TEST(not_null, RawPointer) {
	int  i = 0;
	not_null<int*> p(&i);
}