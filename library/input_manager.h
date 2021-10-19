#pragma once
#include <iostream>
#include <map>
#include "simple_interest.h"
#include "compound_interest.h"
#include "infinite_interest.h"

enum class PercentType {
    simple,
    compound,
    infinite,
};

PercentType GetPercentTypeFromUser();

double GetDoubleValue();

double GetPositiveNumber(std::string param_name);

double CalcPVSimpleInterest();

double CalcPVCompoundInterest();

double CalcPVInfiniteInterest();
