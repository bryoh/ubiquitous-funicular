#include <iostream>

int main() {
  int var = 10;
  int *prt = &var; // Point storing the address of var

  std::cout << "Value of var: " << var << std::endl;
  std::cout << "Address of var: " << &var << std::endl;
  std::cout << "Pointer ptr points to: " << prt << std::endl;
  std::cout << "Value at ptr: " << *prt << std::endl;

  return 0;
}
