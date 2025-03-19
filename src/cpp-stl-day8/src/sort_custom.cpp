#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>


int main() {
  std::ifstream file("data.csv");
  if (!file.is_open()) return 1;


  std::string line;
  std::getline(file, line); // Skip the header
  //
  std::vector<std::tuple<std::string, int, std::string>> people;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string name, ageStr, city;
    std::getline(ss, name, ',');
    std::getline(ss, ageStr, ',');
    std::getline(ss, city, ',');

    int age = std::stoi(ageStr);
    people.emplace_back(name, age, city);
  }

  std::sort(people.begin(), people.end(), [](auto& a, auto& b){
    return std::get<1>(a) < std::get<1>(b); //sort by age
  });

  for (const auto& person : people) {
    std::cout << std::get<0>(person) << ", " << std::get<1>(person)
      << ", " << std::get<2>(person) << '\n';
  }
  return 0;
}
