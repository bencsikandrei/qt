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

TEST(AVector2D, IsEqualsToAVectorWithTheSameXYComponents) {
    Vector2D v1 {1, 2};
    Vector2D v2 {1, 2};

    EXPECT_TRUE(v1.equals(v2));
    EXPECT_EQ(v1, v2);
}

TEST(AVector2D, CanUseOperatorsLikeInts) {
    Vector2D v1 {2, 3};
    Vector2D v2 {4, 5};

    Vector2D sum { v1 + v2 };
    Vector2D dif { v1 - v2 };

    Vector2D plusAssign { 0, 0 };
    plusAssign += Vector2D::One;

    EXPECT_EQ(sum, Vector2D(6, 8));
    EXPECT_EQ(dif, Vector2D(-2, -2));
    EXPECT_EQ(plusAssign, Vector2D::One);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
