#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << num << " is positive." << std::endl;
    } else if (num < 0) {
        std::cout << num << " is negative." << std::endl;
    } else {
        std::cout << "You entered zero." << std::endl;
    }

    std::cout << "Counting from 1 to " << num << ":" << std::endl;
    for (int i = 1; i <= num; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

