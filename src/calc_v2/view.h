#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "controller.h"
#include "credit_calc.h"
#include "deposit_calc.h"
#include "graf.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private slots:
  void on_res_clicked();

  void on_pushButton_2_clicked();
  void digits();

  void on_pushButton_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

 private:
  Ui::View *ui;
  s21::controller *c = new s21::controller();
  Credit_Calc credit;
  Graf grafik;
  deposit_calc deposit;
};
#endif  // VIEW_H
