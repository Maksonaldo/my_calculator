
#ifndef CALCCREDITMODEL_H
#define CALCCREDITMODEL_H
#include <cmath>

namespace my {
class CalcCreditModel {
 private:
  CalcCreditModel *model_;

 public:
  //  CalcCreditModel(){};
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

#endif  // CALCCREDITMODEL_H
