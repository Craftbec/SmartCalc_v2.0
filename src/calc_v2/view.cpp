#include "view.h"

#include "./ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View) {
  ui->setupUi(this);
  connect(ui->zero, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->one, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->two, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->three, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->four, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->five, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->six, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->seven, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->eight, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->nine, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->dot, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->val_e, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Brackets, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Brackets2, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Div, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->val_x, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Add, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Sub, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Mult, SIGNAL(clicked()), this, SLOT(digits()));

  connect(ui->cos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->Pow, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(digits()));
}

View::~View() { delete ui; }

void View::digits() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "cos(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
  } else if (button->text() == "sin(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
  } else if (button->text() == "tan(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
  } else if (button->text() == "acos(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
  } else if (button->text() == "asin(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
  } else if (button->text() == "atan(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
  } else if (button->text() == "log(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "log(");
  } else if (button->text() == "√x") {
    ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
  } else if (button->text() == "xʸ") {
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
  } else if (button->text() == "ln(x)") {
    ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
  } else if (button->text() == "mod") {
    ui->lineEdit->setText(ui->lineEdit->text() + "%");
  } else {
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
  }
}

void View::on_res_clicked() {
  QString string = ui->lineEdit->text();
  std::string str = string.toStdString();
  double value_x = ui->doubleSpinBox->text().toDouble();
  c->total(str, value_x);
  ui->lineEdit->setText(QString::fromStdString(str));
}

void View::on_pushButton_2_clicked() { ui->lineEdit->setText(""); }

void View::on_pushButton_clicked() {
  if (ui->lineEdit->text().size()) {
    ui->lineEdit->setText(ui->lineEdit->text().chopped(1));
  }
}

void View::on_pushButton_3_clicked() {
  QString string = ui->lineEdit->text();
  std::string str = string.toStdString();
  //    std::pair<std::vector<double>, std::vector<double>> res;

  grafik.gr(str);
}

void View::on_pushButton_4_clicked() {
  if (!credit.isVisible()) {
    credit.show();
  }
}

void View::on_pushButton_5_clicked() {
  if (!deposit.isVisible()) {
    deposit.show();
  }
}
