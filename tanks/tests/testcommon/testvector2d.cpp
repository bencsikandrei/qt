#include <gtest/gtest.h>
#include <vector2d.h>

using namespace common;

TEST(AVector2D, IsDefaultConstructibleAndHasDefaultValues) {
    Vector2D v{};

    EXPECT_EQ(v.getX(), Vector2D::value_type{});
    EXPECT_EQ(v.getY(), Vector2D::value_type{});
}

TEST(AVector2D, CanSetItsValues) {
    Vector2D v{};

    v.setX(1);
    v.setY(2);

    EXPECT_EQ(v.getX(), Vector2D::value_type{1});
    EXPECT_EQ(v.getY(), Vector2D::value_type{2});
}

TEST(AVector2D, CorrectlyReturnsItsMagnitudeWhenAskedForIt) {
    Vector2D v{6, 8};

    EXPECT_EQ(v.magnitude(), Vector2D::value_type{10});
}

TEST(AVector2D, CanMakeANormalizedCopyOfItself) {
    Vector2D v{10, 10};

    Vector2D normalizedV { v.normalized() };

    EXPECT_FLOAT_EQ(normalizedV.magnitude (), Vector2D::value_type{1});
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
