#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "calcCreditModel.h"
#include "calculatorModel.h"
namespace my {
class CalculatorController {
 private:
  CalculatorModel *model_;
  CalcCreditModel *credit_model_;

 public:
  CalculatorController(CalculatorModel *model, CalcCreditModel *credit_model)
      : model_(model), credit_model_(credit_model){};
  double calculation_result(std::string &str, double &x);

  double calc_credit_aut(double &sum, double &creditPeriod, double &procent);
  double calc_credit_def(double &payment, double &creditPeriod,
                         double &procent);
  double calc_credit_def_start(double &payment, double &creditPeriod,
                               double &procent);
  double overment_aut(double &platej, double &term, double &sum_credit);
  double sum_aut(double &overment, double &sum_credit);
  double overment_def(double &all_sum, double &sum_credit);
};
}  // namespace my

#endif  // CALCULATORCONTROLLER_H
