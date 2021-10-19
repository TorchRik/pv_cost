#include "simple_interest.h"

double GetPVSimpleInterest(double principal, double percentage, int term_to_maturity, double flat) {
    double pv_value = percentage * principal * ((1 - std::pow(1 / (1 + flat), term_to_maturity)) / flat);
    pv_value += percentage * pow(1 / (1 + flat), term_to_maturity);
    return pv_value;
}