#include <gtest/gtest.h>

#include <score.h>

TEST(AScore, IsDefaultConstructable) {
    Score();
}

TEST(AScore, StartsAtZeroWhenDefaultConstructed) {
    Score score {};

    EXPECT_EQ(score.get(), 0u);
}

TEST(AScore, CanStartAtNonZeroValue) {
    Score score { 10u };

    EXPECT_EQ(score.get(), 10u);
}

TEST(AScore, EqualsOneAfterIncrementWithMultiplierOne) {
    Score score {};

    score.increment();

    EXPECT_EQ(score.get(), 1u);
}

TEST(AScore, CanIncrementUsingOperators) {
    Score score {1u};

    ++score;

    EXPECT_EQ(score.get(), 2u);
}

TEST(AScore, CanBeCorrectlyChained) {
    Score score{};

    EXPECT_EQ((++score).get(), 1u);
}

TEST(AScore, HasMultiplierOneAsDefault) {
    Score score {};

    EXPECT_EQ(score.getMultiplier(), 1u);
}

TEST(AScore, CorrectlySetsMultiplierTo1point25) {
    Score score {};

    score.setMultiplier (Score::Multiplier{1.25});

    EXPECT_FLOAT_EQ(score.getMultiplier (), Score::Multiplier{1.25f});
}

TEST(AScore, WithMultiplier2Increments2TimesFaster) {
    Score score {Score::Points{0u}, Score::Multiplier{2.0f}}; // starts at 0

    ++score;

    EXPECT_EQ(score.get(), Score::Points{2});
}

TEST(AScore, CanBeDoubledByTimesEquals2) {
    Score score { 150u };

    score *= 2;

    EXPECT_EQ(score.get (), Score::Points{300u});
}

// TODO add tests and implementations for operator+, operator-, ..

auto main(int argc, char** argv) -> int {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
