#include <iostream>
#include "input_manager.h"

int main() {
    while (true) {
        PercentType percent_type = GetPercentTypeFromUser();
        if (percent_type == PercentType::simple) {
            std::cout << CalcPVSimpleInterest() << std::endl;
        } else if (percent_type == PercentType::compound) {
            std::cout << CalcPVCompoundInterest() << std::endl;
        }
        std::cout << "If you want to calc new PV enter next:\n";
        std::string user_input;
        std::cin >> user_input;
        if (user_input != "next") {
            break;
        }
    }
}