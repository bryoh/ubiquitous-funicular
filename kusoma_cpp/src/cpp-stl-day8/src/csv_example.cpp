#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

int main() {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cerr << "File not found!\n";
    return 1;
  }
  
  std::string line;
  std::vector<std::string> headers;
  std::vector<std::map<std::string, std::string>>rows;

  bool first_line = true;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string value;
    std::vector<std::string> tokens;

    while (std::getline(ss, value, ',')) {
      tokens.push_back(value);
    }

    if (first_line) {
      headers = tokens;
      first_line = false;
    } else {
      std::map<std::string, std::string> row;
      for (size_t i = 0; i < headers.size(); i++) {
        row[headers[i]] = tokens[i];
      }
      rows.push_back(row);
    }
  }
}
