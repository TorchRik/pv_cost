#pragma once

enum class InterestType {
    simple,
    compound,
    infinite,
};

struct Interest {
    double value;
    InterestType type;
    double compounding_frequency;
};