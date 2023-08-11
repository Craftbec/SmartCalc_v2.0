#include "deposit_calc.h"

#include "ui_deposit_calc.h"

deposit_calc::deposit_calc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::deposit_calc) {
  ui->setupUi(this);
}

deposit_calc::~deposit_calc() { delete ui; }

void deposit_calc::on_comboBox_currentIndexChanged(int index) {
  periodicity_index(index);
}

void deposit_calc::periodicity_index(int a) {
  a++;
  periodicity = a;
}

void deposit_calc::on_comboBox_2_currentIndexChanged(int index) {
  refills_index(index);
}

void deposit_calc::refills_index(int a) {
  a++;
  refills = a;
}

void deposit_calc::payouts_index(int a) {
  a++;
  payouts = a;
}

void deposit_calc::on_comboBox_3_currentIndexChanged(int index) {
  payouts_index(index);
}

void deposit_calc::on_radioButton_clicked(bool checked) {
  if (checked) {
    capitalization = 1;
  } else {
    capitalization = 0;
  }
}

void deposit_calc::on_pushButton_clicked() {
  QString string = ui->lineEdit->text();
  std::string str = string.toStdString();
  int m;
  std::string s1, s2, s3;
  c->check_data(str, m);
  if (m) {
    c->deposit(ui->sum->text().toDouble(), ui->time->text().toInt(), m,
               ui->stavka->text().toDouble(), ui->nalog->text().toDouble(),
               periodicity, capitalization, refills,
               ui->refills_sum->text().toDouble(), payouts,
               ui->period_payouts->text().toDouble(), s1, s2, s3);
  }
  ui->textBrowser->setText(QString::fromStdString(s1));
  ui->textBrowser_2->setText(QString::fromStdString(s2));
  ui->textBrowser_3->setText(QString::fromStdString(s3));
}
