#include <iostream>

class Circle {
private:
  int radius;

public:
  Circle() : radius(0) {}
  Circle(int r) : radius(r) {}

  // Destructor
  ~Circle() { std::cout << "Circle destroyed" << std::endl; }

  // Calculate the area of the circle
  // Area = PI * r^2
  int getArea() { return 3.14 * radius * radius; }
};

int main() {
  Circle c(5);
  std::cout << "Area: " << c.getArea() << std::endl;
  return 0;
}
