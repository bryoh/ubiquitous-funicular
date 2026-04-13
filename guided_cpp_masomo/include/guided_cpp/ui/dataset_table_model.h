#ifndef GUIDED_CPP_UI_DATASET_TABLE_MODEL_H_
#define GUIDED_CPP_UI_DATASET_TABLE_MODEL_H_

#include <QAbstractTableModel>
#include <QVariant>

#include "guided_cpp/core/dataset.h"

namespace guided_cpp {

class DatasetTableModel : public QAbstractTableModel {
 public:
  explicit DatasetTableModel(QObject* parent = nullptr);

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

  void SetDataset(Dataset dataset);
  const Dataset& dataset() const;

 private:
  Dataset dataset_;
};

}  // namespace guided_cpp

#endif  // GUIDED_CPP_UI_DATASET_TABLE_MODEL_H_

