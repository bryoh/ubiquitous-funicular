#include "guided_cpp/csv/csv_importer.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

namespace guided_cpp {

Dataset CsvImporter::ImportFromFile(const std::string& file_path) const {
  std::ifstream input(file_path);
  if (!input.is_open()) {
    throw std::runtime_error("Unable to open CSV file: " + file_path);
  }

  std::string line;
  if (!std::getline(input, line)) {
    return Dataset();
  }

  std::vector<std::string> headers = SplitCsvLine(line);
  std::vector<Dataset::Row> rows;

  while (std::getline(input, line)) {
    if (line.empty()) {
      continue;
    }
    rows.push_back(SplitCsvLine(line));
  }

  return Dataset(std::move(headers), std::move(rows));
}

Dataset::Row CsvImporter::SplitCsvLine(const std::string& line) {
  std::stringstream stream(line);
  std::string cell;
  Dataset::Row row;

  while (std::getline(stream, cell, ',')) {
    row.push_back(cell);
  }

  if (!line.empty() && line.back() == ',') {
    row.push_back("");
  }

  return row;
}

}  // namespace guided_cpp

