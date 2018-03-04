#include <gtest/gtest.h>
#include <position.h>

using namespace common;

using XPos = typename Position::XPos;
using YPos = typename Position::YPos;

TEST(APosition, CanBeDefaultConstructed)
{
    Position pos{};
}

TEST(APosition, HasZeroValuesWhenDefaultConstructed)
{
    Position_t<double> pos{};
    ASSERT_DOUBLE_EQ(pos.getX(), Position::XPos{});
    ASSERT_DOUBLE_EQ(pos.getY(), Position::YPos{});
}

TEST(APosition, CanBeConstructedWithOnlyOneDimension)
{
    Position posWithX{XPos{10}};
    ASSERT_EQ(posWithX.getX(), 10);
    ASSERT_EQ(posWithX.getY(), Position::YPos{});
}

TEST(APosition, CanSetBothItsValues)
{
    Position pos{};

    pos.setX(XPos{10});
    pos.setY(YPos{15});

    ASSERT_EQ(pos.getX(), XPos{10});
    ASSERT_EQ(pos.getY(), YPos{15});
}

TEST(APosition, CanBeResetToAnother)
{
    Position original{10, 20};

    original.reset(1, 2);

    EXPECT_EQ(original, Position(1, 2));

    Position after{3, 4};
    original.reset(after);

    EXPECT_EQ(original, after);
}

TEST(APosition, CanBeDeepCopied)
{
    Position original{10, 15};
    Position copy{original};

    ASSERT_EQ(original, copy);

    copy.setX(20);

    ASSERT_NE(original, copy);
}

TEST(APosition, PrintsXAndYSeparatedByCommas)
{
    Position pos{1, 2};

    std::ostringstream oss{};
    oss << pos;
    std::string output{oss.str()};
    std::string expected{"(1, 2)"};
    ASSERT_EQ(expected, output);
}

TEST(APosition, canIncrementXandY)
{
    Position finalPos{11, 9};
    Position pos{10, 10};
    pos.moveOnX(1);
    pos.moveOnY(-1);
    ASSERT_EQ(pos, finalPos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
