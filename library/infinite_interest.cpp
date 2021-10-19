#include "infinite_interest.h"

double GetPVInfiniteInterest(double principal, double percentage, int term_to_maturity, double flat) {
    const double e = 2.718281828459045;
    double simple_percentage = std::pow(e, percentage) - 1;
    return GetPVSimpleInterest(principal, simple_percentage, term_to_maturity, flat);
}