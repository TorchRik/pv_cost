#pragma once
#include <iostream>
#include "simple_interest.h"
#include "compound_interest.h"

enum class PercentType {
    simple,
    compound,
};

PercentType GetPercentTypeFromUser();

double GetDoubleValue();

double GetPositiveNumber(std::string param_name);

double CalcPVSimpleInterest();

double CalcPVCompoundInterest();
