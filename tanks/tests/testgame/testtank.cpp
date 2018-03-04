#include<gtest/gtest.h>

#include <tank.h>

TEST(ATank, CanBeDefaultConstructed) {
    Tank t {};
}

TEST(ATank, IsAtPositionZeroWhenCreated) {
    Tank t {};

    EXPECT_EQ(t.getPosition(), Vehicle::Position{});
}

TEST(ATank, CanBePositionedElseWhereAtConstruction) {
    Tank t45 { 100, 150 };

    EXPECT_EQ(t45.getPosition (), Vehicle::Position(100, 150));

    Vehicle::Position elseWhere { 200, 420 };
    Tank t55 { elseWhere };

    EXPECT_EQ(t55.getPosition (), elseWhere);
}

TEST(ATank, HasDefaultHealthWhenDefaultConstructed) {
    Tank t {};

    EXPECT_EQ(t.getHealth (), common::DEFAULT_VEHICLE_HEALTH);
}

TEST(ATank, IsAliveWhenConstructed) {
    Tank t {};

    EXPECT_TRUE(t.isAlive());
}

TEST(ATank, MovesToNewPositionWhenCommandedTo) {
    Tank t {0, 0};
    Vehicle::Position newPos { 100, 100 };

    t.move (newPos);

    EXPECT_EQ(t.getPosition (), newPos);

    t.move(200, 200);

    EXPECT_EQ(t.getPosition (), Vehicle::Position(200, 200));
}

TEST(ATank, ReturnsItsLastPositionAfterCallingMove) {
    Vehicle::Position initialPosition { 300, 300 };
    Tank t { initialPosition };

    auto positionBeforeMove{t.move(250, 250)};

    EXPECT_EQ(positionBeforeMove, initialPosition);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
