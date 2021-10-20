#pragma once
#include <iostream>
#include <map>
#include "calc_pv_value.h"
#include "calc_ytm.h"
#include "interests.h"

InterestType GetInterestTypeFromUser();

double GetDoubleValue();

double GetPositiveNumber(std::string param_name);

std::pair<double, double> CalcYtmAndPV();