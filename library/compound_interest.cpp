#include "compound_interest.h"

double GetPVCompoundInterest(double principal, double percentage, double term_to_maturity,
                             double flat, double frequency_of_accrual) {
    double simple_percentage = std::pow(1 + percentage / frequency_of_accrual, frequency_of_accrual) - 1;
    return GetPVSimpleInterest(principal, simple_percentage, term_to_maturity, flat);
}