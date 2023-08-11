#include "graf.h"

#include "ui_graf.h"

Graf::Graf(QWidget *parent) : QMainWindow(parent), ui(new Ui::Graf) {
  ui->setupUi(this);
}

Graf::~Graf() { delete ui; }

void Graf::gr(std::string str) {
  expression = str;
  std::pair<std::vector<double>, std::vector<double>> res;
  res =
      c->grafic(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value(), str);
  if (chartView != nullptr) {
    delete chartView;
  }
  print(res);
}

void Graf::print(std::pair<std::vector<double>, std::vector<double>> res) {
  //   QScatterSeries *series = new QScatterSeries();
  QLineSeries *series = new QLineSeries();
  auto j = res.second.begin();
  for (auto i = res.first.begin(); i != res.first.end(); i++, j++) {
    series->append(*i, *j);
  }
  QChart *chart = new QChart();
  chart->legend()->hide();
  chart->addSeries(series);
  chart->createDefaultAxes();
  chart->setTitle("Schedule");
  chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  ui->gg->layout()->addWidget(chartView);
  show();
}

void Graf::on_doubleSpinBox_valueChanged(double arg1) { gr(expression); }

void Graf::on_doubleSpinBox_2_valueChanged(double arg1) { gr(expression); }
