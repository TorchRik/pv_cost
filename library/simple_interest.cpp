#include "simple_interest.h"

double GetPVSimpleInterest(double principal, double percentage, int term_to_maturity, double flat) {
    if (flat == 0) {
        return percentage * principal * term_to_maturity + principal;
    }
    double pv_value = principal * percentage * (1 - pow(1 / (1 + flat), term_to_maturity)) / flat;
    pv_value += principal * pow(1 / (1 + flat), term_to_maturity);
    return pv_value;
}