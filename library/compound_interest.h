#pragma once
#include <cmath>
#include "simple_interest.h"

double GetPVCompoundInterest(double principal, double percentage, int term_to_maturity,
                             double flat, double compounding_frequency);