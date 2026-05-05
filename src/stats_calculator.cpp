#include "stats_calculator.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>

bool StatsCalculator::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return false;
    }

    numbers.clear();
    double value;
    while (file >> value) {
        numbers.push_back(value);
    }

    if (numbers.empty()) {
        std::cerr << "Error: No numbers found in file." << std::endl;
        return false;
    }
    return true;
}

double StatsCalculator::getSum() const {
    return std::accumulate(numbers.begin(), numbers.end(), 0.0);
}

double StatsCalculator::getAverage() const {
    if (numbers.empty()) return 0.0;
    return getSum() / numbers.size();
}

double StatsCalculator::getMin() const {
    if (numbers.empty()) return 0.0;
    return *std::min_element(numbers.begin(), numbers.end());
}

double StatsCalculator::getMax() const {
    if (numbers.empty()) return 0.0;
    return *std::max_element(numbers.begin(), numbers.end());
}

size_t StatsCalculator::getCount() const {
    return numbers.size();
}