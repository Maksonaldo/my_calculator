#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H
#include <cmath>
#include <stack>
#include <string>

enum { LN = 1, SIN, TAN, COS, LOG, ACOS, ASIN, ATAN, SQRT };

namespace my {

class CalculatorModel {
 private:
  std::string current_;             // private
  std::stack<char> stack_current;   // private
  std::stack<double> stack_result;  // p

  void get_function(int &type);
  int get_priority(char &index);
  int get_name_function(std::string &str);
  bool check_function(char str);
  void arithmetic_operations(char &oper);
  std::string get_current();
  std::string transformation_postfix_notation(std::string &str);

 public:
  CalculatorModel(){};
  // void result();
  double calculation_result(std::string &str, double &x);
};

}  // namespace my

#endif  // CALCULATORMODEL_H
