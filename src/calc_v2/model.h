#ifndef MODEL_H
#define MODEL_H
// 1) +
// 2) -
// 3) *
// 4) /
// 5) %
// 6) ^
// 7) sqrt
// 8) acos
// 9) asin
// 10) atan
// 11) sin
// 12) cos
// 13) tan
// 14) ln
// 15) log
// 16) унарный плюс
// 17) унарный минус
// 18) (
// 19) )
// 20) число
// 21) х

#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>

namespace s21 {
class model {
 private:
  struct Lexeme {
   public:
    double value_;
    int operation_;
    int priority_;

   public:
    Lexeme(double value, int operation, int priority)
        : value_(value), operation_(operation), priority_(priority) {}
    double get_value() { return this->value_; }
    int get_operation() { return this->operation_; }
    int get_priority() { return this->priority_; }
    void set_value(double value) { this->value_ = value; }
    void set_operation(int operation) { this->operation_ = operation; }
    void set_priority(int priority) { this->priority_ = priority; }
  };

 public:
  std::list<Lexeme> pars(const std::string &str);
  void polis_notation(std::list<Lexeme> &List);
  bool check_priority(std::list<Lexeme> &support, int i);
  void value_x(double value, std::list<Lexeme> &List);
  int priority_function(int a);
  int pars_function(const char *str);
  bool check_number(char a);
  bool check_string_size(const std::string &str);
  bool check_mod(const char *str);
  bool check_bracket(const char *str);
  bool check_point(const char *str);
  int validation(const std::string &str);
  void replacement_dot(std::string &str, const std::string a,
                       const std::string b, const std::string c);
  bool check_last_symbol(const char *s);
  bool check_log(const char *s);
  bool check_ln(const char *s);
  bool check_sqrt(const char *s);
  bool check_sin(const char *s);
  bool check_tan(const char *s);
  bool check_cos(const char *s);
  bool check_a(const char *s);
  bool check_after_unar(const char s);
  bool check_after_number(const char s);
  bool check_after_sign(const char s);
  void replacement(std::string &str, const std::string a, const std::string b);
  double counting(std::list<Lexeme> &List);
  void operations_unar(int oper, std::list<double> &res);
  void operations(int oper, std::list<double> &res);
  void functions(int oper, std::list<double> &res);
  int total(std::string &str, double x);
  void check_result(std::string &s);
  void check_result_e(std::string &s);
  void check_e(std::string &s, const char t);
  std::pair<std::vector<double>, std::vector<double>> grafic(
      double min, double max, const std::string &str);
  void credit(double sum, int time, double stavka, int t, std::string &s1,
              std::string &s2, std::string &s3);
  void credit_ann(double sum, int time, double stavka, std::string &s1,
                  std::string &s2, std::string &s3);
  void credit_dif(double sum, int time, double stavka, std::string &s1,
                  std::string &s2, std::string &s3);
  void check_data(std::string data, int &m);
  void days(int month, int &days);
  void frequency_of_payments(int periodicity, int &period);
  void periodicity_calculation(int refills, int &period);
  void deposit(double sum, int time, int data, double stavka, double nalog,
               int periodicity, int capitalization, int refills,
               double refills_sum, int payouts, double period_payouts,
               std::string &s1, std::string &s2, std::string &s3);

  void print_l(std::list<s21::model::Lexeme> &List) {
    for (auto i = List.begin(); i != List.end(); i++) {
      std::cout << (*i).get_value() << '|' << (*i).get_operation() << '|'
                << (*i).get_priority() << std::endl;
    }
  }
};

}  // namespace s21
#endif