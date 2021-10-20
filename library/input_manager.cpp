#include "input_manager.h"

InterestType GetInterestTypeFromUser() {
    std::string user_input;
    std::map<std::string, InterestType> possibles_types = {
            {"inf", InterestType::infinite},
            {"sim", InterestType::simple},
            {"com", InterestType::compound},
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

std::pair<double, double> CalcYtmAndPV() {
    Interest interest;
    double principal = GetPositiveNumber("principal");
    interest.type = GetInterestTypeFromUser();
    interest.value = GetPositiveNumber("interest value") / 100;
    if (interest.type == InterestType::compound) {
        interest.compounding_frequency = GetPositiveNumber("compounding frequency");
    }
    int term_to_maturity = GetPositiveNumber("term to maturity");
    double flat = GetPositiveNumber("flat") / 100;
    double ytm = GetYtm(interest);
    double pv = GetPV(principal, ytm, term_to_maturity, flat);
    return {ytm, pv};
}