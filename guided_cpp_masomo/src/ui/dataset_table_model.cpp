#include "guided_cpp/ui/dataset_table_model.h"

#include <utility>

namespace guided_cpp {

DatasetTableModel::DatasetTableModel(QObject* parent) : QAbstractTableModel(parent) {}

int DatasetTableModel::rowCount(const QModelIndex& parent) const {
  if (parent.isValid()) {
    return 0;
  }
  return static_cast<int>(dataset_.row_count());
}

int DatasetTableModel::columnCount(const QModelIndex& parent) const {
  if (parent.isValid()) {
    return 0;
  }
  return static_cast<int>(dataset_.column_count());
}

QVariant DatasetTableModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid() || role != Qt::DisplayRole) {
    return QVariant();
  }

  const auto& rows = dataset_.rows();
  if (index.row() >= static_cast<int>(rows.size())) {
    return QVariant();
  }

  const auto& row = rows[index.row()];
  if (index.column() >= static_cast<int>(row.size())) {
    return QVariant();
  }

  return QString::fromStdString(row[index.column()]);
}

QVariant DatasetTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role != Qt::DisplayRole) {
    return QVariant();
  }

  if (orientation == Qt::Horizontal) {
    const auto& headers = dataset_.headers();
    if (section >= 0 && section < static_cast<int>(headers.size())) {
      return QString::fromStdString(headers[section]);
    }
  }

  if (orientation == Qt::Vertical) {
    return section + 1;
  }

  return QVariant();
}

void DatasetTableModel::SetDataset(Dataset dataset) {
  beginResetModel();
  dataset_ = std::move(dataset);
  endResetModel();
}

const Dataset& DatasetTableModel::dataset() const { return dataset_; }

}  // namespace guided_cpp

