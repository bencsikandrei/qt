#include <score.h>

Score::Score(Points defaultPoints, Multiplier defaultMultiplier)
    : m_score { defaultPoints }
    , m_multiplier { defaultMultiplier }
{

}
Score::Score(Score const& rhs)
    : m_score { rhs.m_score }
    , m_multiplier { rhs.m_multiplier }
{

}

Score::Points Score::increment(Points howMany) {
    m_score += m_multiplier * howMany;
    return m_score;
}

Score& Score::operator++() {
    increment (Points{1u});
    return *this;
}

Score& Score::operator*=(Multiplier times) {
    m_score *= times;
    return *this;
}
