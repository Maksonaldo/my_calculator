#include "calcCreditModel.h"
using my::CalcCreditModel;

double CalcCreditModel::calc_credit_aut(double &sum, double &creditPeriod,
                                        double &procent) {
  double result = procent / 12 / 100;
  double platej = sum * (result * pow(1 + result, creditPeriod) /
                         (pow(1 + result, creditPeriod) - 1));
  return platej;
}

double CalcCreditModel::calc_credit_def(double &payment, double &creditPeriod,
                                        double &procent) {
  double vznos = payment / creditPeriod;
  double sum = 0;
  double start = (payment * (0.01 * procent)) / 12;
  for (int i = 0; i < creditPeriod - 1; i++) {
    double ostZad = payment - vznos;
    payment = ostZad;
    double dolProc = (ostZad * procent * 0.01) / 12.0;
    double P = vznos + dolProc;
    sum = P + sum;
  }
  return sum + start + vznos;
}
double CalcCreditModel::calc_credit_def_start(double &payment,
                                              double &creditPeriod,
                                              double &procent) {
  double vznos = payment / creditPeriod;
  double start = (payment * (0.01 * procent)) / 12;
  return start + vznos;
}
double CalcCreditModel::overment_aut(double &platej, double &term,
                                     double &sum_credit) {
  return (platej * term) - sum_credit;
}
double CalcCreditModel::sum_aut(double &overment, double &sum_credit) {
  return overment + sum_credit;
}
double CalcCreditModel::overment_def(double &all_sum, double &sum_credit) {
  return all_sum - sum_credit;
}
