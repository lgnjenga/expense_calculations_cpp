#include "../include/stats_calculator.h"
#include <iostream>
#include <cassert>

// Simple test macro
#define TEST(condition, testName) \
    do { \
        if (condition) \
            std::cout << "[PASS] " << testName << std::endl; \
        else \
            std::cout << "[FAIL] " << testName << std::endl; \
    } while(0)

void testLoadAndCalculate() {
    StatsCalculator calc;
    // Create a temporary test file
    std::ofstream testFile("test_data.txt");
    testFile << "10\n20\n30\n";
    testFile.close();

    bool loaded = calc.loadFromFile("test_data.txt");
    TEST(loaded == true, "Load from file");
    TEST(calc.getCount() == 3, "Count");
    TEST(calc.getSum() == 60.0, "Sum");
    TEST(calc.getAverage() == 20.0, "Average");
    TEST(calc.getMin() == 10.0, "Minimum");
    TEST(calc.getMax() == 30.0, "Maximum");

    remove("test_data.txt");
}

void testEmptyFile() {
    StatsCalculator calc;
    std::ofstream testFile("empty.txt");
    testFile.close();

    bool loaded = calc.loadFromFile("empty.txt");
    TEST(loaded == false, "Empty file handling");

    remove("empty.txt");
}

int main() {
    std::cout << "Running tests...\n";
    testLoadAndCalculate();
    testEmptyFile();
    std::cout << "Tests completed.\n";
    return 0;
}