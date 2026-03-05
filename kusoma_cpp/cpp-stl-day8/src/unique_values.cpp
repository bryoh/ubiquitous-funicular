#include <iostream>
#include <fstream>
#include <sstream>
#include <set>


int main() {
  std::ifstream file("data.csv");
  if (!file.is_open())  return 1;

  std::string line;
  std::getline(file, line); // Skip the header

  std::set<std::string> cities;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string name, age, city;

    std::getline(ss, name, ',');
    std::getline(ss, age, ',');
    std::getline(ss, city, ',');
    cities.insert(city);
  }

  std::cout << "Unique cities: ";
  for (const auto& city : cities) {
    std::cout << city << " ";
  }
  return 0;
}
