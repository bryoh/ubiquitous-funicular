#include <iostream>

int main() {
  int* arr = new int[5];

  for (int i=0; i<5; i++) {
    arr[i] = i;
    std::cout << "arr[" << i << "]" << arr[i] << std::endl;
  }

  delete[] arr;
  arr = nullptr;

  return 0;
}
