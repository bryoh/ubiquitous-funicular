#include "guided_cpp/ui/main_window.h"

#include <exception>

#include <QAction>
#include <QFileInfo>
#include <QFileDialog>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QSplitter>
#include <QStatusBar>
#include <QTableView>

#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

#include "guided_cpp/csv/csv_importer.h"
#include "guided_cpp/ui/dataset_table_model.h"

QT_CHARTS_USE_NAMESPACE

namespace guided_cpp {

MainWindow::MainWindow()
    : table_model_(new DatasetTableModel(this)),
      status_label_(new QLabel("Ready")),
      open_csv_action_(nullptr),
      table_view_(new QTableView(this)),
      chart_view_(nullptr) {
  setWindowTitle("CSV Chart Studio");
  resize(960, 640);

  SetupCentralLayout();
  statusBar()->addWidget(status_label_);
  SetupMenu();
}

void MainWindow::OpenCsv() {
  const QString file_path = QFileDialog::getOpenFileName(
      this,
      "Open CSV",
      QString(),
      "CSV files (*.csv);;All files (*)");

  if (file_path.isEmpty()) {
    return;
  }

  try {
    CsvImporter importer;
    current_dataset_ = importer.ImportFromFile(file_path.toStdString());
    table_model_->SetDataset(current_dataset_);
    UpdateChart();
    status_label_->setText(
        QString("Loaded %1 rows from %2")
            .arg(static_cast<int>(current_dataset_.row_count()))
            .arg(QFileInfo(file_path).fileName()));
  } catch (const std::exception& ex) {
    QMessageBox::critical(this, "CSV Import Error", ex.what());
    status_label_->setText("Import failed");
  }
}

void MainWindow::SetupCentralLayout() {
  table_view_->setModel(table_model_);
  table_view_->setAlternatingRowColors(true);
  table_view_->setSelectionBehavior(QAbstractItemView::SelectRows);
  table_view_->setSelectionMode(QAbstractItemView::SingleSelection);
  table_view_->horizontalHeader()->setStretchLastSection(true);

  auto* chart = new QChart();
  chart->setTitle("Import a CSV to render the first numeric chart");
  chart_view_ = new QChartView(chart, this);
  static_cast<QChartView*>(chart_view_)->setRenderHint(QPainter::Antialiasing);

  auto* splitter = new QSplitter(this);
  splitter->addWidget(table_view_);
  splitter->addWidget(chart_view_);
  splitter->setStretchFactor(0, 3);
  splitter->setStretchFactor(1, 2);
  setCentralWidget(splitter);
}

void MainWindow::UpdateChart() {
  auto* chart_widget = static_cast<QChartView*>(chart_view_);
  auto* chart = new QChart();
  chart->legend()->setVisible(false);

  if (current_dataset_.column_count() < 2 || current_dataset_.row_count() == 0) {
    chart->setTitle("Need at least two columns and one data row");
    chart_widget->setChart(chart);
    return;
  }

  auto* set = new QBarSet(QString::fromStdString(current_dataset_.headers()[1]));
  QStringList categories;

  for (const auto& row : current_dataset_.rows()) {
    if (row.size() < 2) {
      continue;
    }

    bool ok = false;
    const double value = QString::fromStdString(row[1]).toDouble(&ok);
    if (!ok) {
      continue;
    }

    categories << QString::fromStdString(row[0]);
    *set << value;
  }

  if (set->count() == 0) {
    chart->setTitle("Second column is not numeric enough for the starter chart");
    chart_widget->setChart(chart);
    return;
  }

  auto* series = new QBarSeries(chart);
  series->append(set);
  chart->addSeries(series);
  chart->setTitle("Starter chart: column 1 labels vs column 2 values");

  auto* axis_x = new QBarCategoryAxis(chart);
  axis_x->append(categories);
  chart->addAxis(axis_x, Qt::AlignBottom);
  series->attachAxis(axis_x);

  auto* axis_y = new QValueAxis(chart);
  axis_y->setTitleText(QString::fromStdString(current_dataset_.headers()[1]));
  chart->addAxis(axis_y, Qt::AlignLeft);
  series->attachAxis(axis_y);

  chart_widget->setChart(chart);
}

void MainWindow::SetupMenu() {
  QMenu* file_menu = menuBar()->addMenu("&File");
  open_csv_action_ = file_menu->addAction("&Open CSV");
  connect(open_csv_action_, &QAction::triggered, this, &MainWindow::OpenCsv);
  file_menu->addAction("Export &PNG");
  file_menu->addAction("Export &CSV");
  file_menu->addSeparator();

  QAction* quit_action = file_menu->addAction("&Quit");
  connect(quit_action, &QAction::triggered, this, &QWidget::close);

  QMenu* help_menu = menuBar()->addMenu("&Help");
  help_menu->addAction("Roadmap Notes");
}

}  // namespace guided_cpp
