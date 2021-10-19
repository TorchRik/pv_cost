#include "simple_interest.h"
#include "compound_interest.h"
#include "infinite_interest.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

double eps = 0.001;

TEST_CASE("simple_interest") {
    REQUIRE(std::abs(GetPVSimpleInterest(100, 0.1, 1, 0) - 110) < eps);
    REQUIRE(std::abs(GetPVSimpleInterest(100, 0.1, 1, 0.1) - 100) < eps);
    REQUIRE(std::abs(GetPVSimpleInterest(100, 0.1, 2, 0.2) - 84.7222) < eps);
}

TEST_CASE("compound_interest") {
    REQUIRE(std::abs(GetPVCompoundInterest(100, 0.1, 1, 0, 1) - GetPVSimpleInterest(100, 0.1, 1, 0)) < eps);
    REQUIRE(std::abs(GetPVCompoundInterest(100, 0.1, 1, 0.1, 1) - GetPVSimpleInterest(100, 0.1, 1, 0.1)) < eps);
    REQUIRE(std::abs(GetPVCompoundInterest(100, 0.1, 2, 0.1, 2) - GetPVSimpleInterest(100, 0.1025, 2, 0.1)) < eps);
}

TEST_CASE("infinite_interest") {
    REQUIRE(std::abs(GetPVInfiniteInterest(100, 0.1, 1, 0) - GetPVSimpleInterest(100, 0.10517, 1, 0)) < eps);
    REQUIRE(std::abs(GetPVInfiniteInterest(100, 0.2, 1, 0.1) - GetPVSimpleInterest(100, 0.2214, 1, 0.1)) < eps);
    REQUIRE(std::abs(GetPVInfiniteInterest(100, 0.05, 2, 0.1) - GetPVSimpleInterest(100, 0.051271, 2, 0.1)) < eps);
}
