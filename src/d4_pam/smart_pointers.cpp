#include <memory>

std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(100);
std::shared_ptr<int> sharedPtr2 = sharedPtr1;  // Share ownership
std::cout << *sharedPtr1 << ", " << *sharedPtr2;  // Output: 100, 100
