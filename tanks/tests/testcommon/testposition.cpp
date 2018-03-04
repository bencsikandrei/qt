#include <gtest/gtest.h>
#include <position.h>

using namespace common;

using XPos = typename Position<int>::XPos;
using YPos = typename Position<int>::YPos;

TEST(APosition, CanBeDefaultConstructed)
{
    Position<int> pos{};
}

TEST(APosition, HasZeroValuesWhenDefaultConstructed)
{
    Position<double> pos{};
    ASSERT_DOUBLE_EQ(pos.getX(), Position<int>::XPos{});
    ASSERT_DOUBLE_EQ(pos.getY(), Position<int>::YPos{});
}

TEST(APosition, CanBeConstructedWithOnlyOneDimension)
{
    Position<int> posWithX{XPos{10}};
    ASSERT_EQ(posWithX.getX(), 10);
    ASSERT_EQ(posWithX.getY(), Position<int>::YPos{});
}

TEST(APosition, CanSetBothItsValues)
{
    Position<int> pos{};

    pos.setX(XPos{10});
    pos.setY(YPos{15});

    ASSERT_EQ(pos.getX(), XPos{10});
    ASSERT_EQ(pos.getY(), YPos{15});
}

TEST(APosition, CanBeResetToAnother)
{
    Position<int> original{10, 20};

    original.reset(1, 2);

    EXPECT_EQ(original, Position<int>(1, 2));

    Position<int> after{3, 4};
    original.reset(after);

    EXPECT_EQ(original, after);
}

TEST(APosition, CanBeDeepCopied)
{
    Position<int> original{10, 15};
    Position<int> copy{original};

    ASSERT_EQ(original, copy);

    copy.setX(20);

    ASSERT_NE(original, copy);
}

TEST(APosition, PrintsXAndYSeparatedByCommas)
{
    Position<int> pos{1, 2};

    std::ostringstream oss{};
    oss << pos;
    std::string output{oss.str()};
    std::string expected{"(1, 2)"};
    ASSERT_EQ(expected, output);
}

TEST(APosition, canIncrementXandY)
{
    Position<int> finalPos{11, 9};
    Position<int> pos{10, 10};
    pos.moveOnX(1);
    pos.moveOnY(-1);
    ASSERT_EQ(pos, finalPos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
