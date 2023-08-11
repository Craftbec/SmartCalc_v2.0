#ifndef GRAF_H
#define GRAF_H

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QMainWindow>
#include <QScatterSeries>

#include "controller.h"

namespace Ui {
class Graf;
}

class Graf : public QMainWindow {
  Q_OBJECT

 public:
  explicit Graf(QWidget *parent = nullptr);
  ~Graf();

 private:
  Ui::Graf *ui;
  s21::controller *c = new s21::controller();
  void print(std::pair<std::vector<double>, std::vector<double>> res);
  std::string expression;
  QChartView *chartView = nullptr;

 public:
  void gr(std::string str);
 private slots:
  void on_doubleSpinBox_valueChanged(double arg1);
  void on_doubleSpinBox_2_valueChanged(double arg1);
};

#endif  // GRAF_H
