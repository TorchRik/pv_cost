#include "input_manager.h"

PercentType GetPercentTypeFromUser() {
    PercentType percent_type;
    std::string user_input;
    std::map<std::string, PercentType> possibles_types = {
            {"inf", PercentType::infinite},
            {"sim", PercentType::simple},
            {"com", PercentType::compound},
    };
    std::cout << "You want to calc PV using compound, simple or infinite interest? (Input com, sim or inf)\n";
    for (std::cin >> user_input; possibles_types.find(user_input) == possibles_types.end(); std::cin >> user_input) {
        std::cout << "You entered an incorrect interest type, try again (Input com, sim or inf)\n";
    }
    return possibles_types[user_input];
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
        if (principal >= 0) {
            return principal;
        }
        std::cout << param_name + " should be positive, try again\n";
    }
}

double CalcPVSimpleInterest() {
    double principal = GetPositiveNumber("principal");
    double percentage = GetPositiveNumber("percentage") / 100;
    int term_to_maturity = GetPositiveNumber("term to maturity");
    double flat = GetPositiveNumber("flat") / 100;
    return GetPVSimpleInterest(principal, percentage, term_to_maturity, flat);
}

double CalcPVCompoundInterest() {
    double principal = GetPositiveNumber("principal");
    double percentage = GetPositiveNumber("percentage") / 100;
    int term_to_maturity = GetPositiveNumber("term to maturity");
    double flat = GetPositiveNumber("flat") / 100;
    double compounding_frequency = GetPositiveNumber("compounding frequency");
    return GetPVCompoundInterest(principal, percentage, term_to_maturity, flat, compounding_frequency);
}

double CalcPVInfiniteInterest() {
    double principal = GetPositiveNumber("principal");
    double percentage = GetPositiveNumber("percentage") / 100;
    int term_to_maturity = GetPositiveNumber("term to maturity");
    double flat = GetPositiveNumber("flat") / 100;
    return GetPVInfiniteInterest(principal, percentage, term_to_maturity, flat);
}
