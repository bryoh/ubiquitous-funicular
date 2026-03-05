#include <iostream>
#include <iostream>

int main() {
  int userInt;
  std::string userName;

  std::cout << "Enter an integer";
  std::cin >> userInt;

  std::cout << "Enter your name: ";
  std::cin.ignore();
  std::getline(std::cin, userName);

  std::cout << "Hello, " << userName << "! You entered: " << userInt << std::endl;

  return 0;

}
