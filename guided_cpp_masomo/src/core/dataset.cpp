#include "guided_cpp/core/dataset.h"

#include <utility>

namespace guided_cpp {

Dataset::Dataset(std::vector<std::string> headers, std::vector<Row> rows)
    : headers_(std::move(headers)), rows_(std::move(rows)) {}

const std::vector<std::string>& Dataset::headers() const { return headers_; }

const std::vector<Dataset::Row>& Dataset::rows() const { return rows_; }

std::size_t Dataset::column_count() const { return headers_.size(); }

std::size_t Dataset::row_count() const { return rows_.size(); }

bool Dataset::empty() const { return headers_.empty() && rows_.empty(); }

}  // namespace guided_cpp

