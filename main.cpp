#include <iostream>
#include "input_manager.h"

int main() {
    while (true) {
        auto [ytm, pv] = CalcYtmAndPV();
        std::cout << "YTM is " << ytm * 100 << "%\nPV is " << pv << "\n";

        std::cout << "If you want to calc new PV enter next:\n";
        std::string user_input;
        std::cin >> user_input;
        if (user_input != "next") {
            break;
        }
    }
}