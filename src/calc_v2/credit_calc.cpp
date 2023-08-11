#include "credit_calc.h"

#include "ui_credit_calc.h"

Credit_Calc::Credit_Calc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Credit_Calc) {
  ui->setupUi(this);
  ui->radioButton->setChecked(true);
}

Credit_Calc::~Credit_Calc() { delete ui; }

void Credit_Calc::on_pushButton_clicked() {
  std::string s1, s2, s3;
  c->credit(ui->doubleSpinBox->text().toDouble(), ui->spinBox_2->text().toInt(),
            ui->doubleSpinBox_2->text().toDouble(), t, s1, s2, s3);
  ui->textBrowser->setText(QString::fromStdString(s1));
  ui->textBrowser_2->setText(QString::fromStdString(s2));
  ui->textBrowser_3->setText(QString::fromStdString(s3));
}

void Credit_Calc::on_radioButton_clicked(bool checked) {
  if (checked) t = 1;
}

void Credit_Calc::on_radioButton_2_clicked(bool checked) {
  if (checked) t = 2;
}
