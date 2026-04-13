#include <QApplication>

#include "guided_cpp/ui/main_window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  guided_cpp::MainWindow window;
  window.show();

  return app.exec();
}

