#include "headings/Heading.h"
#include "gtest/gtest.h"

using UKControllerPlugin::Headings::Heading;

namespace UKControllerPluginTest::Headings {
    struct HeadingValueCase
    {
        int expected;
        Heading heading;
    };

    class HeadingValueTest : public testing::TestWithParam<HeadingValueCase>
    {
    };

    TEST_P(HeadingValueTest, ItHasExpectedValue)
    {
        const auto& testCase = GetParam();
        EXPECT_EQ(testCase.expected, testCase.heading);
    }

    INSTANTIATE_TEST_CASE_P(
        HeadingValues,
        HeadingValueTest,
        testing::Values(
            HeadingValueCase{360, Heading::North},
            HeadingValueCase{360, Heading::N},
            HeadingValueCase{45, Heading::NorthEast},
            HeadingValueCase{45, Heading::NE},
            HeadingValueCase{90, Heading::East},
            HeadingValueCase{90, Heading::E},
            HeadingValueCase{135, Heading::SouthEast},
            HeadingValueCase{135, Heading::SE},
            HeadingValueCase{180, Heading::South},
            HeadingValueCase{180, Heading::S},
            HeadingValueCase{225, Heading::SouthWest},
            HeadingValueCase{225, Heading::SW},
            HeadingValueCase{270, Heading::West},
            HeadingValueCase{270, Heading::W},
            HeadingValueCase{315, Heading::NorthWest},
            HeadingValueCase{315, Heading::NW}));

    struct HeadingComparisonCase
    {
        Heading left;
        Heading right;
        bool expected;
    };

    class HeadingLessThanTest : public testing::TestWithParam<HeadingComparisonCase>
    {
    };

    TEST_P(HeadingLessThanTest, EvaluatesCorrectly)
    {
        const auto& testCase = GetParam();
        EXPECT_EQ(testCase.expected, testCase.left < testCase.right);
    }

    INSTANTIATE_TEST_CASE_P(
        HeadingLessThan,
        HeadingLessThanTest,
        testing::Values(
            HeadingComparisonCase{Heading::SE, Heading::NW, true},
            HeadingComparisonCase{Heading::NW, Heading::SW, false}));

    class HeadingGreaterThanEqualTest : public testing::TestWithParam<HeadingComparisonCase>
    {
    };

    TEST_P(HeadingGreaterThanEqualTest, EvaluatesCorrectly)
    {
        const auto& testCase = GetParam();
        EXPECT_EQ(testCase.expected, testCase.left >= testCase.right);
    }

    INSTANTIATE_TEST_CASE_P(
        HeadingGreaterThanEqual,
        HeadingGreaterThanEqualTest,
        testing::Values(
            HeadingComparisonCase{Heading::SE, Heading::E, true},
            HeadingComparisonCase{Heading::East, Heading::E, true},
            HeadingComparisonCase{Heading::SW, Heading::W, false}));

    struct DoubleHeadingComparisonCase
    {
        double left;
        Heading right;
        bool expected;
    };

    class DoubleHeadingLessThanTest : public testing::TestWithParam<DoubleHeadingComparisonCase>
    {
    };

    TEST_P(DoubleHeadingLessThanTest, EvaluatesCorrectly)
    {
        const auto& testCase = GetParam();
        EXPECT_EQ(testCase.expected, testCase.left < testCase.right);
    }

    INSTANTIATE_TEST_CASE_P(
        DoubleHeadingLessThan,
        DoubleHeadingLessThanTest,
        testing::Values(
            DoubleHeadingComparisonCase{180.0, Heading::NW, true},
            DoubleHeadingComparisonCase{315.0, Heading::SW, false}));

    class DoubleHeadingGreaterThanEqualTest : public testing::TestWithParam<DoubleHeadingComparisonCase>
    {
    };

    TEST_P(DoubleHeadingGreaterThanEqualTest, EvaluatesCorrectly)
    {
        const auto& testCase = GetParam();
        EXPECT_EQ(testCase.expected, testCase.left >= testCase.right);
    }

    INSTANTIATE_TEST_CASE_P(
        DoubleHeadingGreaterThanEqual,
        DoubleHeadingGreaterThanEqualTest,
        testing::Values(
            DoubleHeadingComparisonCase{180.0, Heading::E, true},
            DoubleHeadingComparisonCase{90.0, Heading::E, true},
            DoubleHeadingComparisonCase{225.0, Heading::W, false}));

    class HeadingTest : public testing::Test
    {
    };

    TEST_F(HeadingTest, ItDoesntTruncateHeadingLessThan360)
    {
        EXPECT_EQ(45, UKControllerPlugin::Headings::TruncateHeading(45));
    }

    TEST_F(HeadingTest, ItTruncatesHeadingGreaterThan360)
    {
        EXPECT_EQ(45, UKControllerPlugin::Headings::TruncateHeading(405));
    }

    TEST_F(HeadingTest, ItTruncatesHeadingEqualTo360)
    {
        EXPECT_EQ(0, UKControllerPlugin::Headings::TruncateHeading(360));
    }

    TEST_F(HeadingTest, ItCalculatesPerpendicularHeadingWithNoTruncate)
    {
        EXPECT_EQ(90, UKControllerPlugin::Headings::PerpendicularHeading(0));
    }

    TEST_F(HeadingTest, ItCalculatesPerpendicularHeadingWithTruncate)
    {
        EXPECT_EQ(90, UKControllerPlugin::Headings::PerpendicularHeading(360));
    }
} // namespace UKControllerPluginTest::Headings
