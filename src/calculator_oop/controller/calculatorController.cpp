#include "calculatorController.h"

using my::CalculatorController;

double CalculatorController::calculation_result(std::string &str, double &x) {
  return model_->calculation_result(str, x);
}

double CalculatorController::calc_credit_aut(double &sum, double &creditPeriod,
                                             double &procent) {
  return credit_model_->calc_credit_aut(sum, creditPeriod, procent);
}
double CalculatorController::calc_credit_def(double &payment,
                                             double &creditPeriod,
                                             double &procent) {
  return credit_model_->calc_credit_def(payment, creditPeriod, procent);
}
double CalculatorController::calc_credit_def_start(double &payment,
                                                   double &creditPeriod,
                                                   double &procent) {
  return credit_model_->calc_credit_def_start(payment, creditPeriod, procent);
}
double CalculatorController::overment_aut(double &platej, double &term,
                                          double &sum_credit) {
  return credit_model_->overment_aut(platej, term, sum_credit);
}
double CalculatorController::sum_aut(double &overment, double &sum_credit) {
  return credit_model_->sum_aut(overment, sum_credit);
}
double CalculatorController::overment_def(double &all_sum, double &sum_credit) {
  return credit_model_->overment_def(all_sum, sum_credit);
}
