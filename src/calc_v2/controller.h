#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
namespace s21 {
class controller {
 private:
  s21::model model_;

 public:
  int total(std::string &str, double x);
  std::pair<std::vector<double>, std::vector<double>> grafic(
      double min, double max, const std::string &str);
  void credit(double sum, int time, double stavka, int t, std::string &s1,
              std::string &s2, std::string &s3);
  void check_data(std::string data, int &m);
  void deposit(double sum, int time, int data, double stavka, double nalog,
               int periodicity, int capitalization, int refills,
               double refills_sum, int payouts, double period_payouts,
               std::string &s1, std::string &s2, std::string &s3);
};
}  // namespace s21
#endif