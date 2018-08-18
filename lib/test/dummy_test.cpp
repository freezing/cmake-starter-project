#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <dummy.h>

using namespace dummy;

TEST(Dummy, DummyTest) {
    Dummy dummy(4);
    ASSERT_EQ(dummy.GetDummy(), 4);
}