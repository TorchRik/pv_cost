#include "calc_pv_value.h"
#include "calc_ytm.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

double eps = 0.001;

TEST_CASE("calc_ytm") {
    REQUIRE(std::abs(GetYtm({0.1, InterestType::simple, 0}) - 0.1) < eps);
    REQUIRE(std::abs(GetYtm({0.1, InterestType::compound, 1}) - 0.1) < eps);
    REQUIRE(std::abs(GetYtm({0.1, InterestType::compound, 2}) - 0.1025) < eps);
    REQUIRE(std::abs(GetYtm({0.1, InterestType::infinite, 0}) - 0.10517) < eps);
}

TEST_CASE("calc_pv_value") {
    REQUIRE(std::abs(GetPV(100, 0.1, 1, 0) - 110) < eps);
    REQUIRE(std::abs(GetPV(100, 0.1, 1, 0.1) - 100) < eps);
    REQUIRE(std::abs(GetPV(100, 0.1, 2, 0.2) - 84.7222) < eps);
}