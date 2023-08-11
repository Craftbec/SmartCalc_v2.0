#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

#include <QMainWindow>

#include "controller.h"
namespace Ui {
class deposit_calc;
}

class deposit_calc : public QMainWindow {
  Q_OBJECT

 public:
  explicit deposit_calc(QWidget *parent = nullptr);
  ~deposit_calc();

 private slots:
  void on_comboBox_currentIndexChanged(int index);
  void periodicity_index(int a);
  void refills_index(int a);
  void payouts_index(int a);
  void on_comboBox_2_currentIndexChanged(int index);

  void on_comboBox_3_currentIndexChanged(int index);

  void on_radioButton_clicked(bool checked);

  void on_pushButton_clicked();

 private:
  Ui::deposit_calc *ui;
  int periodicity = 1;
  int refills = 1;
  int payouts = 1;
  int capitalization = 0;
  s21::controller *c = new s21::controller();
};

#endif  // DEPOSIT_CALC_H
