#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QMainWindow>

#include "controller.h"

namespace Ui {
class Credit_Calc;
}

class Credit_Calc : public QMainWindow {
  Q_OBJECT

 public:
  explicit Credit_Calc(QWidget *parent = nullptr);
  ~Credit_Calc();

 private slots:
  void on_pushButton_clicked();

  void on_radioButton_clicked(bool checked);

  void on_radioButton_2_clicked(bool checked);

 private:
  Ui::Credit_Calc *ui;
  s21::controller *c = new s21::controller();
  int t = 1;
};

#endif  // CREDIT_CALC_H
