#include <exception>
#include <iostream>

#include "guided_cpp/csv/csv_importer.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: csv_preview_cli <path-to-csv>\n";
    return 1;
  }

  try {
    guided_cpp::CsvImporter importer;
    const guided_cpp::Dataset dataset = importer.ImportFromFile(argv[1]);

    std::cout << "Headers: " << dataset.column_count() << '\n';
    std::cout << "Rows: " << dataset.row_count() << '\n';

    for (const auto& header : dataset.headers()) {
      std::cout << header << ' ';
    }
    std::cout << '\n';
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }

  return 0;
}

