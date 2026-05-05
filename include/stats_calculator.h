#pragma once

#include <vector>
#include <string>

/**
 * @brief Calculates statistics from a list of numbers.
 * 
 * This class demonstrates the Facade pattern: it provides a simple
 * interface to complex operations (reading files, computing stats).
 */
class StatsCalculator {
public:
    /**
     * @brief Load numbers from a text file (one number per line).
     * @param filename Path to the file.
     * @return true if successfully loaded and at least one number exists.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Get the sum of all numbers.
     */
    double getSum() const;

    /**
     * @brief Get the average (mean) of all numbers.
     */
    double getAverage() const;

    /**
     * @brief Get the minimum value.
     */
    double getMin() const;

    /**
     * @brief Get the maximum value.
     */
    double getMax() const;

    /**
     * @brief Get the count of numbers.
     */
    size_t getCount() const;

private:
    std::vector<double> numbers;
};
