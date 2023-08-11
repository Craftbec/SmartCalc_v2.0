#include <gtest/gtest.h>

#include "../calc_v2/controller.cpp"
#include "../calc_v2/controller.h"
#include "../calc_v2/model.cpp"

TEST(test_assert, calc_1) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("2+3");
  c.total(tmp, 0);
  result = 2 + 3;
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_2) {
  s21::controller c;
  s21::model m;
  std::string tmp = ("15.4+16.7*4.532%5");
  c.total(tmp, 0);
  double result = 16.0844;
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_3) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("sin(cos(0.5*25))");
  c.total(tmp, 0);
  result = sin(cos(0.5 * 25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_4) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("sin(cos(0.5*x))");
  c.total(tmp, 25);
  result = sin(cos(0.5 * 25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_5) {
  s21::controller c;
  std::string tmp = ("sin(cos(0.5*x*-))");
  c.total(tmp, 0);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_assert, calc_6) {
  s21::controller c;
  std::string tmp = ("2*-cos()");
  c.total(tmp, 0);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_assert, calc_7) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("2*-cos(5)");
  c.total(tmp, 25);
  result = (2 * -cos(5));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_8) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("5-(-7)");
  c.total(tmp, 25);
  result = (5 - (-7));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_9) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("5+(+7)");
  c.total(tmp, 25);
  result = (5 + (+7));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_10) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("123+45*67/89");
  c.total(tmp, 25);
  result = 156.876404;
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_11) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("2^2^3");
  c.total(tmp, 25);
  result = (256);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_12) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("cos(x)");
  c.total(tmp, 25);
  result = (cos(25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_13) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("sin(x)");
  c.total(tmp, 25);
  result = (sin(25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_14) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("tan(x)");
  c.total(tmp, 25);
  result = (tan(25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_15) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("tan(x)-sin(x)*cos(x)");
  c.total(tmp, 25);
  result = (tan(25) - sin(25) * cos(25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_16) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("atan(x)-asin(x)*acos(x)");
  c.total(tmp, 25);
  result = (atan(25) - asin(25) * acos(25));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_17) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("sqrt(789)");
  c.total(tmp, 25);
  result = (sqrt(789));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_18) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("ln(789)");
  c.total(tmp, 25);
  result = (log(789));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_19) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("log(123)");
  c.total(tmp, 25);
  result = (log10(123));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_20) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("sqrt(-789)");
  c.total(tmp, 25);
  result = (sqrt(-789));
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_21) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("-(+8)");
  c.total(tmp, 0);
  result = -(+8);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_22) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("+(-8)");
  c.total(tmp, 0);
  result = +(-8);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_23) {
  s21::controller c;
  std::string tmp = ("4-)*(");
  c.total(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_assert, calc_24) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("4%6");
  c.total(tmp, 0);
  result = fmod(4, 6);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_25) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("6^7");
  c.total(tmp, 0);
  result = pow(6, 7);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_26) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("34*89e-4");
  c.total(tmp, 0);
  result = (34 * 89e-4);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_27) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("34*89e+2");
  c.total(tmp, 0);
  result = (34 * 89e+2);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_28) {
  s21::controller c;
  std::string tmp = ("cos(");
  c.total(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_assert, calc_29) {
  s21::controller c;
  double sum = 100000;
  int time = 6;
  double rate = 22;
  int t = 1;
  std::string s1, s2, s3;
  c.credit(sum, time, rate, t, s1, s2, s3);
  ASSERT_EQ(s1, "17752.29");
  ASSERT_EQ(s2, "6513.79");
  ASSERT_EQ(s3, "106513.79");
}

TEST(test_assert, calc_30) {
  s21::controller c;
  double sum = 100000;
  int time = 6;
  double rate = 22;
  int t = 2;
  std::string s1, s2, s3;
  c.credit(sum, time, rate, t, s1, s2, s3);
  ASSERT_EQ(s1, "18500  ...  16972.22");
  ASSERT_EQ(s2, "6416.66");
  ASSERT_EQ(s3, "106416.66");
}

TEST(test_assert, calc_31) {
  s21::controller c;
  double sum = 100000;
  int time = 6;
  double rate = 22;
  double nalog = 4.25;
  int period = 1;
  int kap = 1;
  int p = 1;
  double p_s = 1000;
  int s = 0;
  double s_d = 0;
  int data = 2;
  std::string s1, s2, s3;
  c.deposit(sum, time, data, rate, nalog, period, kap, p, p_s, s, s_d, s1, s2,
            s3);
  ASSERT_EQ(s1, "11701.1");
  ASSERT_EQ(s2, "0");
  ASSERT_EQ(s3, "117701.1");
}
TEST(test_assert, calc_32) {
  s21::controller c;
  double sum = 100000;
  int time = 6;
  double rate = 22;
  double nalog = 4.25;
  int period = 5;
  int kap = 1;
  int p = 1;
  double p_s = 1000;
  int s = 0;
  double s_d = 0;
  int data = 2;
  std::string s1, s2, s3;
  c.deposit(sum, time, data, rate, nalog, period, kap, p, p_s, s, s_d, s1, s2,
            s3);
  ASSERT_EQ(s1, "11186.25");
  ASSERT_EQ(s2, "0");
  ASSERT_EQ(s3, "117186.25");
}

TEST(test_assert, calc_33) {
  s21::controller c;
  double sum = 1000000000;
  int time = 6;
  double rate = 22;
  double nalog = 4.25;
  int period = 5;
  int kap = 1;
  int p = 1;
  double p_s = 1000;
  int s = 1;
  double s_d = 345;
  int data = 3;
  std::string s1, s2, s3;
  c.deposit(sum, time, data, rate, nalog, period, kap, p, p_s, s, s_d, s1, s2,
            s3);
  ASSERT_EQ(s1, "110904288");
  ASSERT_EQ(s2, "4711838.5");
  ASSERT_EQ(s3, "1110908218");
}

TEST(test_assert, calc_34) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("ln(e)");
  c.total(tmp, 0);
  result = 1;
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_35) {
  s21::controller c;
  std::string tmp = (".");
  c.total(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_assert, calc_36) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = (".3");
  c.total(tmp, 0);
  result = .3;
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_37) {
  s21::controller c;
  double result = 0;
  std::string tmp = ("34e+3*5e+45");
  c.total(tmp, 0);
  char bubber[50];
  result = (34e+3 * 5e+45);
  sprintf(bubber, "%e", result);
  ASSERT_EQ(tmp, bubber);
}

TEST(test_assert, calc_38) {
  s21::controller c;
  s21::model m;
  double result = 0;
  std::string tmp = ("4.+.3");
  c.total(tmp, 0);
  result = (4. + .3);
  std::string res = std::to_string(result);
  m.check_result(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_assert, calc_39) {
  s21::controller c;
  int m = 0;
  std::string tmp = "14.02";
  c.check_data(tmp, m);
  int res = 2;
  ASSERT_EQ(m, res);
}

TEST(test_assert, calc_40) {
  s21::controller c;
  int m = 0;
  std::string tmp = "14.04";
  c.check_data(tmp, m);
  int res = 4;
  ASSERT_EQ(m, res);
}

TEST(test_assert, calc_41) {
  s21::controller c;
  int m = 0;
  std::string tmp = "14.01";
  c.check_data(tmp, m);
  int res = 1;
  ASSERT_EQ(m, res);
}

TEST(test_assert, calc_42) {
  s21::controller c;
  std::string tmp = ("2*x");
  std::pair<std::vector<double>, std::vector<double>> res;
  res = c.grafic(-1, 1, tmp);
  auto j = res.second.begin();
  auto i = res.first.begin();
  ASSERT_DOUBLE_EQ(*i, -1);
  ASSERT_DOUBLE_EQ(*j, -2);
}
