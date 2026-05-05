#include "../include/stats_calculator.h"
#include <iostream>
#include <iomanip>

int main() {
    StatsCalculator calc;

    // Load from file (relative path from build directory)
    if (!calc.loadFromFile("../data/expenses.txt")) {
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Expense Statistics ===\n";
    std::cout << "Count:   " << calc.getCount() << " items\n";
    std::cout << "Total:   $" << calc.getSum() << "\n";
    std::cout << "Average: $" << calc.getAverage() << "\n";
    std::cout << "Minimum: $" << calc.getMin() << "\n";
    std::cout << "Maximum: $" << calc.getMax() << "\n";

    return 0;
}