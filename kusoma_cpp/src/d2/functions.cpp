#include <iostream>

#include <iostream>

// Function declaration
int addNumbers(int a, int b) {
    return a + b;
}

void printGreeting(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main() {
    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    int sum = addNumbers(x, y);
    std::cout << "The sum is: " << sum << std::endl;

    std::string name;
    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    printGreeting(name);

    return 0;
}

