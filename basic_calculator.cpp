#include <iostream>
#include <cmath>
#include "basic_calculator.h"


double add(double num1, double num2) { // This function adds two numbers together

    return num1 + num2;
}

double subtract(double num1, double num2){ // This function subtracts one number from the other

    return num1 - num2;
}

double multiply(double num1, double num2) { // This function multiplies two numbers together

    return num1 * num2;
    
}

double divide(double num1, double num2) { // This function divides num1 by num2

        return num1 / num2;
}

double exponent(double num1, double num2) { // This function uses the pow()  function within cmath to perform exponent math
    if (num1 < 0) {
        std::cout << "Error: Base can not be zero" << std::endl;
        return 1;
    } else {
        return pow(num1,num2);
    }
}
