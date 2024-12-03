#include <iostream>

class Rectangle {
private:
  int length;
  int width;

  void setDimensions( int l, int w ) {
    length = l;
    width = w;
  }

public:
  void initializeRect(int l, int w ) {
    setDimensions(l, w);
  }
  int getArea() {
    return length * width;
  }


};

int main() {
  Rectangle rect;
  rect.initializeRect(5, 10);
  std::cout << "Area: " << rect.getArea() << std::endl;


  return 0;
}
