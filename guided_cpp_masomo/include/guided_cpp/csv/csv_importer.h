#ifndef GUIDED_CPP_CSV_CSV_IMPORTER_H_
#define GUIDED_CPP_CSV_CSV_IMPORTER_H_

#include <string>

#include "guided_cpp/core/dataset.h"

namespace guided_cpp {

class CsvImporter {
 public:
  Dataset ImportFromFile(const std::string& file_path) const;

 private:
  static Dataset::Row SplitCsvLine(const std::string& line);
};

}  // namespace guided_cpp

#endif  // GUIDED_CPP_CSV_CSV_IMPORTER_H_

