#include "input_manager.h"

PercentType GetPercentTypeFromUser() {
    PercentType percent_type;
    std::string user_input;
    std::cout << "You want to calc PV using compound or simple interest? (Input com or sim)\n";
    for (std::cin >> user_input; user_input != "sim" && user_input != "com"; std::cin >> user_input) {
        std::cout << "Нou entered an incorrect interest type, try again\n";
    }
    if (user_input == "sim") {
        percent_type = PercentType::simple;
    } else {
        percent_type = PercentType::compound;
    }
    return percent_type;
}

double GetDoubleValue() {
    std::string user_input;
    while (true) {
        std::cin >> user_input;
        try {
            return std::stod(user_input);
        } catch (std::exception) {
            std::cout << "Please input a correct number, try again\n";
        }
    }
}

double GetPositiveNumber(std::string param_name) {
    std::cout << "Input " + param_name + "\n";
    while (true) {
        double principal = GetDoubleValue();
        if (principal > 0) {
            return principal;
        }
        std::cout << param_name + " should be greater then 0, try again\n";
    }
}

double CalcPVSimpleInterest() {
    double principal = GetPositiveNumber("principal");
    double percentage = GetPositiveNumber("percentage");
    int term_to_maturity = GetPositiveNumber("term_to_maturity");
    double flat = GetPositiveNumber("flat");
    return GetPVSimpleInterest(principal, percentage, term_to_maturity, flat);
}

double CalcPVCompoundInterest() {
    double principal = GetPositiveNumber("principal");
    double percentage = GetPositiveNumber("percentage");
    int term_to_maturity = GetPositiveNumber("term to maturity");
    double flat = GetPositiveNumber("flat");
    double frequency_of_accrual = GetPositiveNumber("frequency of accrual");
    return GetPVCompoundInterest(principal, percentage, term_to_maturity, flat, frequency_of_accrual);
}
