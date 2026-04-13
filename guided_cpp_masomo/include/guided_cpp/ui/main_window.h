#ifndef GUIDED_CPP_UI_MAIN_WINDOW_H_
#define GUIDED_CPP_UI_MAIN_WINDOW_H_

#include <QMainWindow>

#include "guided_cpp/core/dataset.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QAction;
class QTableView;
class QWidget;
QT_END_NAMESPACE

namespace guided_cpp {

class DatasetTableModel;

class MainWindow : public QMainWindow {
 public:
  MainWindow();

 private:
  void OpenCsv();
  void SetupCentralLayout();
  void SetupMenu();
  void UpdateChart();

  Dataset current_dataset_;
  DatasetTableModel* table_model_;
  QLabel* status_label_;
  QAction* open_csv_action_;
  QTableView* table_view_;
  QWidget* chart_view_;
};

}  // namespace guided_cpp

#endif  // GUIDED_CPP_UI_MAIN_WINDOW_H_
