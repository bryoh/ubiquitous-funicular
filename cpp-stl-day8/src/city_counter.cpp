#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main() {
  std::ifstream file("data.csv");
  if (!file.is_open()) return 1;


  std::string line;
  std::getline(file, line); // Skip the header

  std::map<std::string, int> cityCount;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string name, age, city; 
    std::getline(ss, name, ',');
    std::getline(ss, age, ',');
    std::getline(ss, city, ',');
    cityCount[city]++;
  }


  for (const auto& pair : cityCount) {
    std::cout << pair.first << ": " << pair.second << '\n';
  }
  return 0;
}
