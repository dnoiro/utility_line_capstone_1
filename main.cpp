#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "menu_options.h"
#include "basic_calculator.h"
#include "encrypt_decrypt.h"
#include "statistical_calculator.h"
#include "password_generator.h"

const int MIN = 1;
const int MAX = 5;

int main() {
    bool running = true;
    while (running) {
        displayMenu();
        int input;
        while (!(std::cin >> input) || input < MIN || input > MAX) {
            std::cout << "Error: Invalid input. Please try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (input) {
            case 1: {
                std::cout << "Pick an option" << std::endl;
                std::cout << "1. Add" << std::endl;
                std::cout << "2. Subtract" << std::endl;
                std::cout << "3. Multiply" << std::endl;
                std::cout << "4. Divide" << std::endl;
                std::cout << "5. Exponentiation" << std::endl;

                int option;
                while (!(std::cin >> option) || option < 1 || option > 5) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                double num1, num2;
                std::cout << "Input first number: ";
                std::cin >> num1;
                std::cout << "Input second number: ";
                std::cin >> num2;

                if (option == 1) {
                    std::cout << "Result: " << add(num1, num2) << std::endl;
                } else if (option == 2) {
                    std::cout << "Result: " << subtract(num1, num2) << std::endl;
                } else if (option == 3) {
                    std::cout << "Result: " << multiply(num1, num2) << std::endl;
                } else if (option == 4) {
                    if (num2 == 0) {
                        std::cout << "Error: cannot divide by zero" << std::endl;
                    } else {
                        std::cout << "Result: " << divide(num1, num2) << std::endl;
                    }
                } else if (option == 5) {
                    std::cout << "Result: " << exponent(num1, num2) << std::endl;
                }
                break;
            }

            case 2: {
                std::cout << "Pick an option" << std::endl;
                std::cout << "1. Encrypt" << std::endl;
                std::cout << "2. Decrypt" << std::endl;

                int option;
                while (!(std::cin >> option) || option < 1 || option > 2) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string text;
                std::cout << "Enter the text: ";
                std::getline(std::cin, text);

                int shift;
                std::cout << "Enter the shift amount: ";
                while (!(std::cin >> shift)) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                if (option == 1) {
                    std::cout << "Encrypted: " << encrypt(text, shift) << std::endl;
                } else {
                    std::cout << "Decrypted: " << decrypt(text, shift) << std::endl;
                }
                break;
            }

            case 3: {
                std::cout << "Pick an option" << std::endl;
                std::cout << "1. Mean" << std::endl;
                std::cout << "2. Median" << std::endl;
                std::cout << "3. Mode" << std::endl;

                int option;
                while (!(std::cin >> option) || option < 1 || option > 3) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                int count;
                std::cout << "How many numbers will you enter? ";
                while (!(std::cin >> count) || count < 1) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::vector<double> numbers;
                for (int i = 0; i < count; i++) {
                    double n;
                    std::cout << "Enter number " << (i + 1) << ": ";
                    while (!(std::cin >> n)) {
                        std::cout << "Error: Invalid input. Please try again" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    numbers.push_back(n);
                }

                if (option == 1) {
                    std::cout << "Mean: " << mean(numbers) << std::endl;
                } else if (option == 2) {
                    std::cout << "Median: " << median(numbers) << std::endl;
                } else if (option == 3) {
                    std::cout << "Mode: " << mode(numbers) << std::endl;
                }
                break;
            }

            case 4: {
                int length;
                std::cout << "Enter password length: ";
                while (!(std::cin >> length) || length < 1) {
                    std::cout << "Error: Invalid input. Please try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Generated password: " << generatePassword(length) << std::endl;
                break;
            }

            case 5: {
                std::cout << "Goodbye!" << std::endl;
                running = false;
                break;
            }

            default:
                break;
        }
    }
    return 0;
}
