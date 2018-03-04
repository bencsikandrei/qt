#include "gtest/gtest.h"
#include <bullet.h>
#include <eheading.h>

class ABullet : public ::testing::Test
{
public:
    ABullet()
        : initialPosition(common::Position<int>(10, 10))
        , initialHeading(eHeading::North)
    {
    }

    Bullet                b;
    common::Position<int> initialPosition;
    eHeading              initialHeading;
};

TEST_F(ABullet, IsDefaultContructable)
{
    Bullet();
}

TEST_F(ABullet, HasDefaultPosition)
{
    common::Position<int> initialPosition;
    EXPECT_EQ(b.getPosition(), initialPosition);
}

TEST_F(ABullet, SetsPositionCorrectlyUponConstruction)
{
    Bullet b(initialPosition);
    EXPECT_EQ(b.getPosition(), initialPosition);
}

TEST_F(ABullet, CanChangePositionWithMoveMethod)
{
    Bullet bNorth(initialPosition, eHeading::North);
    Bullet bEast(initialPosition, eHeading::East);
    Bullet bSouth(initialPosition, eHeading::South);
    Bullet bWest(initialPosition, eHeading::West);

    bNorth.move();
    bEast.move();
    bSouth.move();
    bWest.move();

    EXPECT_EQ(bNorth.getPosition(), common::Position<int>(initialPosition).moveOnY(-1));
    EXPECT_EQ(bEast.getPosition(), common::Position<int>(initialPosition).moveOnX(1));
    EXPECT_EQ(bSouth.getPosition(), common::Position<int>(initialPosition).moveOnY(1));
    EXPECT_EQ(bWest.getPosition(), common::Position<int>(initialPosition).moveOnX(-1));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
