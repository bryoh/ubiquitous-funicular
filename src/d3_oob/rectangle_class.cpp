#include <iostream>

class Rectangle {
private:
  int length;
  int width;

public:
  Rectangle() : length(0), width(0) {}
  Rectangle( int l, int w ) : length(l), width(w) {}

  //Destructor
  ~Rectangle() {
    std::cout << "Destructor called" << std::endl;
  }

  int getArea() {
    return length * width;
  }


};

int main() {
  {
    Rectangle rect(5, 10);
    std::cout << "Area: " << rect.getArea() << std::endl;
  } // Destructor is called when rect goes out of scope



  return 0;
}
