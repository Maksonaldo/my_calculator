#include <gtest/gtest.h>
//#include "time.cpp"
#include "../calculator_oop/model/calcCreditModel.h"
#include "../calculator_oop/model/calculatorModel.h"

using my::CalcCreditModel;
using my::CalculatorModel;

//#include <libcsc/time/time.cpp>
//  g++ my_test.cpp -o test -lgtest
// CK_FORK=no leaks --atExit -- ./test

TEST(Caluculator, test_1) {
  CalculatorModel Calc;
  std::string my_str = "-1-(-1)";
  double x = 0;
  double my_result = Calc.calculation_result(my_str, x);
  double result = -1 - (-1);
  EXPECT_EQ(my_result, result);
}

TEST(Caluculator, test_2) {
  CalculatorModel Calc;
  std::string my_str = "-1";
  double x = 0;
  double my_result = Calc.calculation_result(my_str, x);
  double result = -1;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_3) {
  CalculatorModel Calc;
  std::string my_str = "100";
  double x = 0;
  double my_result = Calc.calculation_result(my_str, x);
  double result = 100;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_4) {
  CalculatorModel Calc;
  std::string my_str = "644-285-11+432+12-0.2312+123";
  double x = 0;
  double my_result = Calc.calculation_result(my_str, x);
  double result = 644 - 285 - 11 + 432 + 12 - 0.2312 + 123;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_5) {
  CalculatorModel Calc;
  std::string my_str = "0-222";
  double x = 0;
  double my_result = Calc.calculation_result(my_str, x);
  double result = 0 - 222;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_6) {
  CalculatorModel Calc;
  double x = 1;
  std::string my_str = "sin(x)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sin(1);
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_7) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sin(278 + 234) + 22";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sin(278 + 234) + 22;
  EXPECT_EQ(my_result, result);
}

TEST(Caluculator, test_8) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sqrt(25) + 22";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sqrt(25) + 22;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_9) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sqrt(25)+22*cos(18-99)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sqrt(25) + 22 * cos(18 - 99);
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_10) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "(((((sin(34*12-11))))))";
  double my_result = Calc.calculation_result(my_str, x);
  double result = (((((sin(34 * 12 - 11))))));
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_11) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sin(-45)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sin(-45);
  EXPECT_EQ(my_result, result);
}

TEST(Caluculator, test_12) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "-sin(1)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = -sin(1);
  EXPECT_EQ(my_result, result);
}

TEST(Caluculator, test_14) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sin(1)-cos(10)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sin(1) - cos(10);
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_15) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "sin(1)-(-cos(10))";
  double my_result = Calc.calculation_result(my_str, x);
  double result = sin(1) - (-cos(10));
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_16) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "40.34*((-0.424)/(-252))";
  double my_result = Calc.calculation_result(my_str, x);
  double result = 40.34 * ((-0.424) / (-252));
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_17) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "357.34%(952.34%712.12)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = fmod(357.34, fmod(952.34, 712.12));
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_18) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "97.66/(705.2/2619.)/(-59.59)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = 97.66 / (705.2 / 2619.) / (-59.59);
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_19) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "6916.08*(5855.31*75.6934)*((-3272.10)*4382.36)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = 6916.08 * (5855.31 * 75.6934) * ((-3272.10) * 4382.36);
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_20) {
  double x = 12;
  CalculatorModel Calc;
  std::string my_str = "x*x+x";
  double my_result = Calc.calculation_result(my_str, x);
  double result = x * x + x;
  EXPECT_EQ(my_result, result);
}
TEST(Caluculator, test_21) {
  CalculatorModel Calc;
  double x = 0;
  std::string my_str = "log(123)";
  double my_result = Calc.calculation_result(my_str, x);
  double result = log10(123);
  EXPECT_EQ(my_result, result);
}

TEST(Credit_calc, test_1) {
  CalcCreditModel Credit;
  double sum = 100000;
  double creditPeriod = 17;
  double procent = 15;

  double my_result = Credit.calc_credit_aut(sum, creditPeriod, procent);
  EXPECT_EQ(round(my_result), 6566);
}

TEST(Credit_calc, test_2) {
  CalcCreditModel Credit;
  double sum = 10000;
  double creditPeriod = 3;
  double procent = 11;

  double my_result = Credit.calc_credit_aut(sum, creditPeriod, procent);
  EXPECT_EQ(round(my_result), 3395);
}

TEST(Credit_calc, test_4) {
  CalcCreditModel Credit;
  double payment = 42342;
  double creditPeriod = 44;
  double procent = 20;

  double my_result = Credit.calc_credit_def(payment, creditPeriod, procent);
  EXPECT_EQ(round(my_result), 58220);
}

TEST(Credit_calc, test_5) {
  CalcCreditModel Credit;
  double payment = 43232;
  double creditPeriod = 2;
  double procent = 11;
  double my_result =
      Credit.calc_credit_def_start(payment, creditPeriod, procent);
  EXPECT_EQ(round(my_result), 22012);
}

TEST(Credit_calc, test_6) {
  CalcCreditModel Credit;
  double platej = 999;
  double term = 111;
  double sum_credit = 1;

  double my_result = Credit.overment_aut(platej, term, sum_credit);
  EXPECT_EQ(round(my_result), 110888);
}

TEST(Credit_calc, test_7) {
  CalcCreditModel Credit;
  double overment = 11;
  double sum_credit = 10000;

  double my_result = Credit.sum_aut(overment, sum_credit);
  EXPECT_EQ(round(my_result), 10011);
}

TEST(Credit_calc, test_8) {
  CalcCreditModel Credit;
  double all_sum = 12323;
  double sum_credit = 13;
  double my_result = Credit.overment_def(all_sum, sum_credit);
  EXPECT_EQ(round(my_result), 12310);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
