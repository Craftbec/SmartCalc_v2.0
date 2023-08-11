// \file
#include "controller.h"

/// @brief Expression calculation
/// @param str Given expression
/// @param x x value
/// @return Expression values
int s21::controller::total(std::string &str, double x) {
  return this->model_.total(str, x);
}

/// @brief Calculation y by x
/// @param min minimum x
/// @param max maximum x
/// @param str  Given expression
/// @return Couple y/x
std::pair<std::vector<double>, std::vector<double>> s21::controller::grafic(
    double min, double max, const std::string &str) {
  return this->model_.grafic(min, max, str);
}

/// @brief choice of loan calculator depending on the type
/// @param sum Amount of credit
/// @param time Credit term
/// @param stavka Interest rate
/// @param t calculator type
/// @param s1 string for monthly payment
/// @param s2 string from for accrued interest
/// @param s3 string from debt + interest
void s21::controller::credit(double sum, int time, double stavka, int t,
                             std::string &s1, std::string &s2,
                             std::string &s3) {
  this->model_.credit(sum, time, stavka, t, s1, s2, s3);
}

/// @brief Checking if the date is entered correctly
/// @param data date value
/// @param m Month number
void s21::controller::check_data(std::string data, int &m) {
  this->model_.check_data(data, m);
}

/// @brief Deposit calculation
/// @param sum Deposit amount
/// @param time deposit time
/// @param data start date
/// @param stavka annual rate
/// @param nalog tax rate
/// @param periodicity periodicity number
/// @param capitalization presence/absence of capitalization
/// @param refills Replenishment frequency number
/// @param refills_sum Top-up amount
/// @param payouts Removal frequency number
/// @param period_payouts Withdrawal amount
/// @param s1 string for accrued interest
/// @param s2 string for taxes
/// @param s3 string for amounts at the end of the deposit
void s21::controller::deposit(double sum, int time, int data, double stavka,
                              double nalog, int periodicity, int capitalization,
                              int refills, double refills_sum, int payouts,
                              double period_payouts, std::string &s1,
                              std::string &s2, std::string &s3) {
  this->model_.deposit(sum, time, data, stavka, nalog, periodicity,
                       capitalization, refills, refills_sum, payouts,
                       period_payouts, s1, s2, s3);
}