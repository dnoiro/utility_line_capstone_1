#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "statistical_calculator.h"

double mean(const std::vector<double>& inputs) {

    if (inputs.empty()) {
        return 0;
    }

    double sum = 0;

    for (double n : inputs) {
        sum += n;
    }

    return sum / inputs.size();
}

 double median(const std::vector<double> & inputs) {

    if (inputs.empty()) {

        return 0;
    }

    std::vector<double> sorted = inputs; // Copying inputs into a mutable vector
    std::sort(sorted.begin(), sorted.end());

    size_t n = sorted.size();

    if (n % 2 == 0) {

        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    } else {

        return sorted[n / 2];
    }

 }


 double mode(const std::vector<double>& inputs) {

    if (inputs.empty()) {

        return 0;
    }

    std::unordered_map<double, int> frequency;

    for (double input : inputs) {

        frequency[input]++;
    }

    double mode = 0;
    int maxFrequency = 0;

    for (const auto& pair : frequency) {
        if(pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }

    return mode;
 }
