#ifndef GUIDED_CPP_CORE_DATASET_H_
#define GUIDED_CPP_CORE_DATASET_H_

#include <cstddef>
#include <string>
#include <vector>

namespace guided_cpp {

class Dataset {
 public:
  using Row = std::vector<std::string>;

  Dataset() = default;
  Dataset(std::vector<std::string> headers, std::vector<Row> rows);

  const std::vector<std::string>& headers() const;
  const std::vector<Row>& rows() const;

  std::size_t column_count() const;
  std::size_t row_count() const;
  bool empty() const;

 private:
  std::vector<std::string> headers_;
  std::vector<Row> rows_;
};

}  // namespace guided_cpp

#endif  // GUIDED_CPP_CORE_DATASET_H_

