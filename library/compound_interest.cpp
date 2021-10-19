#include "compound_interest.h"

double GetPVCompoundInterest(double principal, double percentage, int term_to_maturity,
                             double flat, double compounding_frequency) {
    double simple_percentage = std::pow(1 + percentage / compounding_frequency, compounding_frequency) - 1;
    return GetPVSimpleInterest(principal, simple_percentage, term_to_maturity, flat);
}