#pragma once
#include <cmath>
#include "simple_interest.h"

double GetPVCompoundInterest(double principal, double percentage, double term_to_maturity,
                             double flat, double frequency_of_accrual);