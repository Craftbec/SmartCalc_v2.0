// \file
#include "model.h"

/// @brief String parser for tokens
/// @param str calculation expression
/// @return List Lexem
std::list<s21::model::Lexeme> s21::model::pars(const std::string &str) {
  std::list<Lexeme> List;
  char first = str[0];
  for (size_t i = 0; i < str.length(); i++) {
    if (check_number(str[i])) {
      if (str[i] == 'e') {
        List.push_back(Lexeme(2.71828182846, 20, 0));
      } else {
        double num = atof(&str[i]);
        List.push_back(Lexeme(num, 20, 0));
        while (check_number(str[i]) || str[i] == '.') {
          i++;
        }
        i--;
      }

    } else if (str[i] == '+' || str[i] == '-') {
      if (first == '+') {
        List.push_back(Lexeme(0, 16, 3));
        first = ';';
      } else if (first == '-') {
        List.push_back(Lexeme(0, 17, 3));
        first = ';';
      } else if ((!check_number(str[i - 1]) && str[i - 1] != 'x' &&
                  str[i - 1] != ')') ||
                 (str[i - 1] == '(')) {
        if (str[i] == '+') List.push_back(Lexeme(0, 16, 3));
        if (str[i] == '-') List.push_back(Lexeme(0, 17, 3));
      } else {
        int operation = pars_function(&str[i]);
        List.push_back(Lexeme(0, operation, priority_function(operation)));
      }
    } else if (str[i] == '*' || str[i] == '/' || str[i] == '%' ||
               str[i] == '^' || str[i] == ')' || str[i] == '(') {
      int operation = pars_function(&str[i]);
      List.push_back(Lexeme(0, operation, priority_function(operation)));
    } else if (str[i] == 'c' || str[i] == 's' || str[i] == 't' ||
               str[i] == 'l' || str[i] == 'a') {
      int operation = pars_function(&str[i]);
      List.push_back(Lexeme(0, operation, priority_function(operation)));
      while (!check_number(str[i]) && str[i] != '(') {
        i++;
      }
      i = i - 1;
    } else if (str[i] == 'x') {
      List.push_back(Lexeme(0, 21, 0));
    }
  }
  return List;
}

/// @brief Polish nation
/// @param List Lexem
void s21::model::polis_notation(std::list<s21::model::Lexeme> &List) {
  std::list<Lexeme> ready, support;
  std::list<Lexeme> tmp;
  tmp = List;
  for (auto i = tmp.begin(); i != tmp.end(); i++) {
    if ((*i).get_operation() == 20) {
      ready.push_back(Lexeme((*i).get_value(), 20, 0));
      List.pop_front();
    } else if ((*i).get_operation() == 19) {
      while (support.back().get_operation() != 18) {
        ready.push_back(Lexeme(0, support.back().get_operation(),
                               support.back().get_priority()));
        support.pop_back();
      }
      support.pop_back();
    } else if ((*i).get_operation() < 19) {
      if (support.empty()) {
        support.push_back(Lexeme(0, (*i).get_operation(), (*i).get_priority()));
        List.pop_front();
      } else {
        if (check_priority(support, (*i).get_priority()) &&
            support.back().get_operation() != 18) {
          while (support.size()) {
            if (check_priority(support, (*i).get_priority()) &&
                support.back().get_operation() != 18) {
              ready.push_back(Lexeme(0, support.back().get_operation(),
                                     support.back().get_priority()));
              support.pop_back();
            } else {
              break;
            }
          }
          support.push_back(
              Lexeme(0, (*i).get_operation(), (*i).get_priority()));
          List.pop_front();
        } else {
          support.push_back(
              Lexeme(0, (*i).get_operation(), (*i).get_priority()));
          List.pop_front();
        }
      }
    }
  }
  while (!support.empty()) {
    ready.push_back(Lexeme(0, support.back().get_operation(),
                           support.back().get_priority()));
    support.pop_back();
  }
  List = ready;
}

/// @brief Priority check
/// @param support Auxiliary List Operation/Function
/// @param i Operation/Function Priority
/// @return true/false
bool s21::model::check_priority(std::list<s21::model::Lexeme> &support, int i) {
  bool res = 0;
  if (!support.empty()) {
    if (i <= support.back().get_priority()) res = 1;
    if (support.back().get_priority() == 3 && i == 3) res = 0;
  }
  return res;
}

/// @brief insert value into x
/// @param value x value
/// @param List List with set x
void s21::model::value_x(double value, std::list<s21::model::Lexeme> &List) {
  std::list<Lexeme> tmp;
  for (auto i = List.begin(); i != List.end(); i++) {
    if ((*i).get_operation() == 21) {
      tmp.push_back(Lexeme(value, 20, 0));
    } else {
      tmp.push_back(
          Lexeme((*i).get_value(), (*i).get_operation(), (*i).get_priority()));
    }
  }
  List = tmp;
}

/// @brief Determining operator/function precedence
/// @param a operator/functions
/// @return priority value
int s21::model::priority_function(int a) {
  int res = 0;
  if (a == 1 || a == 2 || a == 5) res = 1;
  if (a > 2 && a < 6) res = 2;
  if (a == 6) res = 3;
  if (a > 6 && a < 16) res = 4;
  if (a == 18 || a == 19) res = 5;
  return res;
}

/// @brief Specifying an Operator/Function Number
/// @param str calculation expression
/// @return Operator/function number
int s21::model::pars_function(const char *str) {
  int res = 0;
  const char *tmp = str;
  switch (*str) {
    case '+':
      res = 1;
      if (*tmp--) {
        if (*tmp == '(') res = 16;
      }
      break;
    case '-':
      res = 2;
      if (*tmp--) {
        if (*tmp == '(') res = 17;
      }
      break;
    case '*':
      res = 3;
      break;
    case '/':
      res = 4;
      break;
    case '%':
      res = 5;
      break;
    case '^':
      res = 6;
      break;
    case 's':
      if (*(str + 1) == 'q') res = 7;
      if (*(str + 1) == 'i') res = 11;
      break;
    case 'a':
      if (*(str + 1) == 'c') res = 8;
      if (*(str + 1) == 's') res = 9;
      if (*(str + 1) == 't') res = 10;
      break;
    case 'c':
      res = 12;
      break;
    case 't':
      res = 13;
      break;
    case 'l':
      if (*(str + 1) == 'n') res = 14;
      if (*(str + 1) == 'o') res = 15;
      break;
    case '(':
      res = 18;
      break;
    case ')':
      res = 19;
      break;
  }
  return res;
}

/// @brief Checking for a number
/// @param a Character to test
/// @return true/false
bool s21::model::check_number(char a) {
  bool res = 0;
  if ((a >= '0' && a <= '9') || (a == 'e')) res = 1;
  return res;
}

/// @brief Size check calculation expression
/// @param str calculation expression
/// @return true/false
bool s21::model::check_string_size(const std::string &str) {
  bool res = 0;
  if (str.length() > 0 && str.length() < 256) res = 1;
  return res;
}

/// @brief Correctness of entering the remainder of the department
/// @param str calculation expression
/// @return true/false
bool s21::model::check_mod(const char *str) {
  bool res = 0;
  const char *tmp = str;
  if (*tmp++) {
    if (*str--) {
      if (check_after_sign(*tmp) &&
          (check_number(*str) || *str == ')' || *str == 'x'))
        res = 1;
    }
  }
  return res;
}

/// @brief Parentheses check
/// @param str calculation expression
/// @return true/false
bool s21::model::check_bracket(const char *str) {
  bool res = 1;
  int o = 0, z = 0;
  while (*str) {
    if (*str == '(') o++;
    if (*str == ')') z++;
    if (z > o) {
      res = 0;
      break;
    }
    str += 1;
  }
  if (z != o) res = 0;
  return res;
}

/// @brief Checking the dots of a number
/// @param str calculation expression
/// @return true/false
bool s21::model::check_point(const char *str) {
  bool res = 0;
  int point = 0;
  while (check_number(*str) || *str == '.') {
    if (*str == '.') point++;
    str += 1;
  }
  if (point == 0 || point == 1) res = 1;
  return res;
}

/// @brief Проверка валидности calculation expression
/// @param str calculation expression
/// @return yes/no
int s21::model::validation(const std::string &str) {
  bool res = 1;
  if (str.size() == 1) {
    if (str[0] == '.') return res = 0;
  }
  if (check_bracket(&str[0]) && check_last_symbol(&str[str.length() - 1])) {
    for (size_t i = 0; i < (str.length() - 1); ++i) {
      if (check_number(str[i])) {
        res = check_point(&str[i + 1]);
        if (res == 0) return res;
        while (check_number(str[i]) || str[i] == '.') {
          i++;
        }
        if (i != str.length()) i--;
        if (i != str.length()) res = check_after_number(str[i + 1]);

      } else if (str[i] == '^' || str[i] == '%') {
        res = check_mod(&str[i]);
      } else if (str[i] == '*' || str[i] == '/' || str[i] == '^' ||
                 str[i] == '(') {
        res = check_after_sign(str[i + 1]);
      } else if (str[i] == ')') {
        res = check_after_number(str[i + 1]);
      } else if (str[i] == '-' || str[i] == '+') {
        res = check_after_unar(str[i + 1]);
      } else if (str[i] == 'a') {
        res = check_a(&str[i]);
        i += 3;
      } else if (str[i] == 'c') {
        res = check_cos(&str[i]);
        i += 2;
      } else if (str[i] == 't') {
        res = check_tan(&str[i]);
        i += 2;
      } else if (str[i] == 's' && str[i + 1] == 'i') {
        res = check_sin(&str[i]);
        i += 2;
      } else if (str[i] == 's' && str[i + 1] == 'q') {
        res = check_sqrt(&str[i]);
        i += 3;
      } else if (str[i] == 'l' && str[i + 1] == 'o') {
        res = check_log(&str[i]);
        i += 2;
      } else if (str[i] == 'l' && str[i + 1] == 'n') {
        res = check_ln(&str[i]);
        i += 1;
      }
      if (res == 0) return 0;
    }
  } else {
    res = 0;
  }
  return res;
}

/// @brief Adding 0 before .
/// @param str given expression
/// @param a "."
/// @param b "0."
void s21::model::replacement_dot(std::string &str, const std::string a,
                                 const std::string b, const std::string c) {
  int next = 0;
  int prev = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == '.') {
      if (str[i + 1]) {
        next = check_number(str[i + 1]);
        if (!next) {
          str.replace(i, a.size(), c);
        }
        if (next && str[i - 1]) {
          prev = check_number(str[i - 1]);
          if (!prev) {
            str.replace(i, a.size(), b);
          }
        }
        if (i == 0) {
          str = "0" + str;
        }
      }
    }
  }
}

/// @brief Checking the last character of the expression being evaluated
/// @param s Checked character
/// @return true/false
bool s21::model::check_last_symbol(const char *s) {
  bool res = 0;
  if (*s == '.' || *s == ')' || *s == 'x' || check_number(*s)) res = 1;
  return res;
}

/// @brief Checking for correctness of log inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_log(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "log(", 4)) res = 1;
  return res;
}

/// @brief Checking for correctness of ln inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_ln(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "ln(", 3)) res = 1;
  return res;
}

/// @brief Checking for correctness of sqrt inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_sqrt(const char *s) {
  bool res = 0;
  const char *tmp = s;
  tmp += 5;
  if ((!std::strncmp(s, "sqrt(", 5)) && (check_after_sign(*tmp))) res = 1;
  return res;
}

/// @brief Checking for correctness of sin inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_sin(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "sin(", 4)) res = 1;
  return res;
}

/// @brief Checking for correctness of tan inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_tan(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "tan(", 4)) res = 1;
  return res;
}

/// @brief Checking for correctness of cos inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_cos(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "cos(", 4)) res = 1;
  return res;
}

/// @brief Checking for correctness of acos/asin/atan inputs
/// @param s Checked characters
/// @return true/false
bool s21::model::check_a(const char *s) {
  bool res = 0;
  if (!std::strncmp(s, "acos(", 5)) res = 1;
  if (!std::strncmp(s, "asin(", 5)) res = 1;
  if (!std::strncmp(s, "atan(", 5)) res = 1;
  return res;
}

/// @brief Checking value after unary minus
/// @param s Checked character
/// @return true/false
bool s21::model::check_after_unar(const char s) {
  bool res = 0;
  if (check_number(s) || s == '(' || s == 'c' || s == 's' || s == 't' ||
      s == 'a' || s == 'l' || s == '+' || s == '-' || s == 'x')
    res = 1;
  return res;
}

/// @brief Checking value after number
/// @param s Checked character
/// @return true/false
bool s21::model::check_after_number(const char s) {
  bool res = 0;
  if (s == '+' || s == '-' || s == '*' || s == '/' || s == '%' || s == '^' ||
      s == ')')
    res = 1;
  return res;
}

/// @brief Checking value after sign
/// @param s Checked character
/// @return true/false
bool s21::model::check_after_sign(const char s) {
  bool res = 0;
  if (check_number(s) || s == '(' || s == 'c' || s == 's' || s == 't' ||
      s == 'a' || s == 'l' || s == '+' || s == '-' || s == 'x')
    res = 1;
  return res;
}

/// @brief replacement e-/e+ in the computable expression
/// @param str calculated expression
/// @param a e-/e+
/// @param b /10^ / *10^
void s21::model::replacement(std::string &str, const std::string a,
                             const std::string b) {
  size_t i = 0;
  while ((i = str.find(a)) != str.npos) {
    str.replace(i, a.size(), b);
  }
}

/// @brief Expression calculation
/// @param List with tokens
/// @return Expression value
double s21::model::counting(std::list<s21::model::Lexeme> &List) {
  std::list<double> res;
  for (auto &i : List) {
    if (i.get_operation() == 20) {
      res.push_back(i.get_value());
    } else if (i.get_operation() == 16 || i.get_operation() == 17) {
      operations_unar(i.get_operation(), res);
    } else if (i.get_operation() < 7) {
      operations(i.get_operation(), res);
    } else {
      functions(i.get_operation(), res);
    }
  }
  return res.back();
}

/// @brief Evaluation of unary operators
/// @param oper Operation number
/// @param res Expression value
void s21::model::operations_unar(int oper, std::list<double> &res) {
  double result = 0;
  if (oper == 16) result = +res.back();
  if (oper == 17) result = -res.back();
  res.pop_back();
  res.push_back(result);
}

/// @brief Operator evaluation
/// @param oper Operation number
/// @param res Expression value
void s21::model::operations(int oper, std::list<double> &res) {
  double result = 0.0;
  double second = res.back();
  res.pop_back();
  if (oper == 1) result = res.back() + second;
  if (oper == 2) result = res.back() - second;
  if (oper == 3) result = res.back() * second;
  if (oper == 4) result = res.back() / second;
  if (oper == 5) result = fmod(res.back(), second);
  if (oper == 6) result = pow(res.back(), second);
  res.pop_back();
  res.push_back(result);
}

/// @brief Function calculation
/// @param oper Operation number
/// @param res Expression value
void s21::model::functions(int oper, std::list<double> &res) {
  double result = 0;
  if (oper == 7) result = sqrt(res.back());
  if (oper == 8) result = acos(res.back());
  if (oper == 9) result = asin(res.back());
  if (oper == 10) result = atan(res.back());
  if (oper == 11) result = sin(res.back());
  if (oper == 12) result = cos(res.back());
  if (oper == 13) result = tan(res.back());
  if (oper == 14) result = log(res.back());
  if (oper == 15) result = log10(res.back());
  res.pop_back();
  res.push_back(result);
}

/// @brief Expression calculation with validation check
/// @param str Expression to calculate
/// @param x x value
/// @return expression calculated / incorrect expression
int s21::model::total(std::string &str, double x) {
  int result = 0;
  if (check_string_size(str)) {
    replacement(str, "e-", "/10^");
    replacement(str, "e+", "*10^");
    replacement_dot(str, ".", "0.", ".0");
  }
  if (validation(str)) {
    auto tmp = pars(str);
    value_x(x, tmp);
    polis_notation(tmp);
    double res = counting(tmp);
    char buffer[50];
    if ((fabs(res) > 10000000) || (fabs(res) < 0.000001 && res != 0.0)) {
      sprintf(buffer, "%e", res);
    } else {
      sprintf(buffer, "%.6f", res);
    }
    str = buffer;
    check_result(str);
    check_result_e(str);
    result = 1;
  } else {
    str = "ERROR";
  }
  return result;
}

/// @brief Trimming trailing zeros
/// @param s string with result
void s21::model::check_result(std::string &s) {
  int flag = 1;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 'e') {
      flag = 0;
      break;
    }
  }
  if (flag) {
    if (s[s.size() - 1] == '0')
      for (size_t i = s.size() - 1; s[i] == '0'; i--) s.erase(i, 1);
    if (s[s.size() - 1] == '.') s.erase(s.size() - 1, 1);
  }
}

/// @brief Trimming trailing zeros in exponential notation
/// @param s string with result
void s21::model::check_result_e(std::string &s) {
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 'e') return check_e(s, 'e');
  }
}

/// @brief Trimming trailing zeros in exponential notation
/// @param s string with result
/// @param t dot
void s21::model::check_e(std::string &s, const char t) {
  for (size_t i = s.find(t); i > 0; i--) {
    if (s[i] == '0') {
      // s.erase(i, 1);
      // i = i + 1;
    }
  }
}

/// @brief Computing Points for a Graph
/// @param min minimum x value
/// @param max maximum x value
/// @param str expression
/// @return Pair value x y
std::pair<std::vector<double>, std::vector<double>> s21::model::grafic(
    double min, double max, const std::string &str) {
  std::pair<std::vector<double>, std::vector<double>> res;
  std::string tmp_str = str;
  double h = (max - min) / 500;
  for (double X = min; X <= max; X += h) {
    if (total(tmp_str, X)) {
      if (check_number(tmp_str[0]) || tmp_str[0] == '-') {
        res.first.push_back(X);
        double y = atof(&tmp_str[0]);
        res.second.push_back(y);
      }
    }
    tmp_str = str;
  }
  return res;
}

/// @brief choice of loan calculator depending on the type
/// @param sum Amount of credit
/// @param time Credit term
/// @param stavka Interest rate
/// @param t calculator type
/// @param s1 string for monthly payment
/// @param s2 string from for accrued interest
/// @param s3 string from debt + interest
void s21::model::credit(double sum, int time, double stavka, int t,
                        std::string &s1, std::string &s2, std::string &s3) {
  if (t == 1) {
    credit_ann(sum, time, stavka, s1, s2, s3);
  } else if (t == 2) {
    credit_dif(sum, time, stavka, s1, s2, s3);
  }
}

/// @brief Annuity calculator
/// @param sum Amount of credit
/// @param time Credit term
/// @param stavka Interest rate
/// @param s1 string for monthly payment
/// @param s2 string from for accrued interest
/// @param s3 string from debt + interest
void s21::model::credit_ann(double sum, int time, double stavka,
                            std::string &s1, std::string &s2, std::string &s3) {
  double st = (stavka / 100 / 12);
  double monthly_payment = sum * (st + (st / (pow((1 + st), (time)) - 1)));
  double total_payment = monthly_payment * time;
  double overpayment = total_payment - sum;
  double y = floor(monthly_payment * 100) / 100;
  s1 = std::to_string(y);
  y = floor(overpayment * 100) / 100;
  s2 = std::to_string(y);
  y = floor(total_payment * 100) / 100;
  s3 = std::to_string(y);

  check_result(s1);
  check_result(s2);
  check_result(s3);
}

/// @brief differential calculator
/// @param sum Amount of credit
/// @param time Credit term
/// @param stavka Interest rate
/// @param s1 string for monthly payment
/// @param s2 string from for accrued interest
/// @param s3 string from debt + interest
void s21::model::credit_dif(double sum, int time, double stavka,
                            std::string &s1, std::string &s2, std::string &s3) {
  double tmp = sum;
  double St = (sum / time);
  double monthly_payment = (St + sum * stavka / 100 / 12);
  double overpayment;
  double monthly_payment_min;
  for (int i = 0; i < time; i++) {
    double p = (sum * stavka / 100 / 12);
    if ((i + 1) == time) {
      monthly_payment_min = (St + sum * stavka / 100 / 12);
    }
    sum -= (St);
    overpayment += p;
  }
  double total_payment = tmp + overpayment;
  double y = floor(overpayment * 100) / 100;
  s2 = std::to_string(y);
  y = floor(total_payment * 100) / 100;
  s3 = std::to_string(y);
  y = floor(monthly_payment * 100) / 100;

  std::string tmp3 = std::to_string(y);
  y = floor(monthly_payment_min * 100) / 100;
  std::string tmp1 = std::to_string(y);
  check_result(tmp3);
  check_result(tmp1);
  s1 = tmp3 + "  ...  " + tmp1;
  check_result(s2);
  check_result(s3);
}

/// @brief Checking if the date is entered correctly
/// @param data date value
/// @param m Month number
void s21::model::check_data(std::string data, int &m) {
  m = 0;
  if (data.length() == 5) {
    double date = std::stoi(&data[0]);
    double month = std::stoi(&data[3]);
    if (data[2] == '.') {
      if (month == 2 && (date > 0 && date <= 28)) {
        m = month;
      } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                 (date > 0 && date <= 30)) {
        m = month;
      } else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
                  month == 8 || month == 10 || month == 12) &&
                 (date > 0 && date <= 31)) {
        m = month;
      }
    }
  }
}

/// @brief Calculation of the number of days according to the month
/// @param month Month number
/// @param days Amount of days
void s21::model::days(int month, int &days) {
  if (month == 2) {
    days = 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    days = 30;
  } else {
    days = 31;
  }
}

/// @brief Setting the frequency value according to the number
/// @param periodicity Periodicity number
/// @param period Periodicity value
void s21::model::frequency_of_payments(int periodicity, int &period) {
  if (periodicity == 1) period = 1;
  if (periodicity == 2) period = 3;
  if (periodicity == 3) period = 6;
  if (periodicity == 4) period = 12;
  if (periodicity == 5) period = -1;
}

/// @brief Setting the frequency value according to the number
/// @param refills  Replenishment/withdrawal frequency number
/// @param period Periodicity value
void s21::model::periodicity_calculation(int refills, int &period) {
  if (refills == 1) period = 1;
  if (refills == 2) period = 3;
  if (refills == 3) period = 6;
  if (refills == 4) period = 12;
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
void s21::model::deposit(double sum, int time, int data, double stavka,
                         double nalog, int periodicity, int capitalization,
                         int refills, double refills_sum, int payouts,
                         double period_payouts, std::string &s1,
                         std::string &s2, std::string &s3) {
  int i = 1;
  float doxod = 0;
  float proc;
  float itog;
  float nal;
  int period;
  int flag = 0;
  int period_refills;
  int period_payout;
  frequency_of_payments(periodicity, period);
  periodicity_calculation(refills, period_refills);
  periodicity_calculation(payouts, period_payout);
  if (period == -1) {
    capitalization = 0;
    flag = 1;
  }
  while (i <= time) {
    int div;
    days(data, div);
    doxod = sum * stavka * div / 365 / 100;
    proc += doxod;
    itog += doxod;
    if (capitalization) {
      if (!(i % period)) {
        sum += proc;
        proc = 0;
      }
    }
    if (!(i % period_refills)) {
      sum += refills_sum;
    }
    if (!(i % period_payout)) {
      sum -= period_payouts;
    }
    i++;
    data++;
    if (data == 13) data = 1;
  }
  if (flag) {
    sum += itog;
  }
  nal = (1000000 * 7.5 / 100 / 12 * time);
  if (itog > nal) {
    float tmp = itog;
    tmp -= nal;
    nal = tmp * nalog / 100;
  } else {
    nal = 0;
  }
  char tmp1[50];
  sprintf(tmp1, "%.2f", itog);
  char tmp3[50];
  sprintf(tmp3, "%.2f", sum);
  s1 = tmp1;
  s3 = tmp3;
  char tmp2[50];
  sprintf(tmp2, "%.2f", nal);
  s2 = tmp2;
  check_result(s1);
  check_result(s3);
  check_result(s2);
}