#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "C");
  View w;
  w.show();
  return a.exec();
}
