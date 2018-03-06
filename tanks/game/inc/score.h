#pragma once

#include <utils.h>

class Score final {
public:
    using Points = size_t;
    using Multiplier = float;
    explicit Score(Points defaultPoints = Points{0u}, Multiplier defaultMultiplier = Multiplier {1.0f});
    Score(Score const& rhs);
    Score(Score && rhs) = default;
    Score& operator=(Score const& rhs) = default;
    Score& operator=(Score && rhs) = default;

    ~Score() {}

    Score& operator++();
    Score& operator*=(Multiplier times);

    Points get() const { return m_score; }
    Multiplier getMultiplier() const { return m_multiplier; }

    void setMultiplier(Multiplier newMultiplier) { m_multiplier = newMultiplier; }

    Points increment(Points howMany = Points{1u});

private:
    Points m_score;
    Multiplier m_multiplier;
};
