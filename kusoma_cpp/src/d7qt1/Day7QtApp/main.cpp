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
  QVBoxLayout *mainLayout = new QVBoxLayout();

  QLabel *label = new QLabel("Hello, Qt!");
  QLineEdit *nameInput = new QLineEdit();
  nameInput->setPlaceholderText("Enter your name");
  QPushButton *button = new QPushButton("Click me!");
  QLabel *nameLabel = new QLabel();

  QHBoxLayout *horizontalLayout = new QHBoxLayout();
  horizontalLayout->addWidget(nameInput);
  horizontalLayout->addWidget(button);

  mainLayout->addWidget(label);
  mainLayout->addLayout(horizontalLayout);
  mainLayout->addWidget(nameLabel);

  QObject::connect(button, &QPushButton::clicked, [&]() {
      QString name = nameInput->text();
      nameLabel->setText("Hello, " + name + "!");
  });

  centralWidget->setLayout(mainLayout);
  mainwindow.setCentralWidget(centralWidget);

  mainwindow.resize(400, 300);
  mainwindow.show();

  return app.exec();
}
