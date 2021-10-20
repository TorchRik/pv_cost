#include "calc_ytm.h"

double GetYtm(Interest interest) {
    if (interest.type == InterestType::simple) {
        return interest.value;
    } else if (interest.type == InterestType::compound) {
        return std::pow(1 + interest.value / interest.compounding_frequency, interest.compounding_frequency) - 1;
    } else {
        const double e = 2.718281828459045;
        return std::pow(e, interest.value) - 1;
    }
}