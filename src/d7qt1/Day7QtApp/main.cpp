#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QMainWindow mainwindow;
  mainwindow.setWindowTitle("Day 7: Layouts and Widgets");

  QWidget *centralWidget = new QWidget();
  QVBoxLayout *layout = new QVBoxLayout();

  QLabel *label = new QLabel("Hello, Qt!");
  QPushButton *button = new QPushButton("Click me!");
  QLineEdit *editline = new QLineEdit();


  layout ->addWidget(label);
  layout ->addWidget(editline);
  layout ->addWidget(button);

  centralWidget ->setLayout(layout);
  mainwindow.setCentralWidget(centralWidget);




  mainwindow.resize(400, 300);
  mainwindow.show();

  return app.exec();
}
