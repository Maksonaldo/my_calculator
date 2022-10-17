#include "calculatorModel.h"

#include <iostream>

using my::CalculatorModel;

void CalculatorModel::arithmetic_operations(char &oper) {
  double result_val = stack_result.top();
  stack_result.pop();
  double result = 0;
  if (oper == '+') {
    result = stack_result.top() + result_val;
    stack_result.pop();
  } else if (oper == '-') {
    result = stack_result.top() - result_val;
    stack_result.pop();
  } else if (oper == '*') {
    result = stack_result.top() * result_val;
    stack_result.pop();
  } else if (oper == '/') {
    result = stack_result.top() / result_val;
    stack_result.pop();
  } else if (oper == '%') {
    result = fmod(stack_result.top(), result_val);
    stack_result.pop();
  } else if (oper == '^') {
    result = pow(stack_result.top(), result_val);
    stack_result.pop();
  } else if (oper == 'e') {
    if (result_val >= 0) {
      result = stack_result.top() * pow(10, result_val);
    } else {
      result = stack_result.top() * pow(0.1, result_val * (-1));
    }
    stack_result.pop();
  } else if (oper == 'u') {
    result = result_val * -1;
  }
  stack_result.push(result);
}
int CalculatorModel::get_priority(char &index) {
  int prior = 0;
  switch (index) {
    case 'x':
      prior = 0;
      break;
    case '.':
      prior = 0;
      break;
    case ')':
      prior = -1;
      break;
    case '(':
      prior = 1;
      break;
    case '+':
      prior = 2;
      break;
    case '-':
      prior = 2;
      break;
    case '*':
      prior = 3;
      break;
    case '/':
      prior = 3;
      break;
    case '^':
      prior = 4;
      break;
    case '%':
      prior = 4;
      break;
    case 'e':
      prior = 5;
      break;
    case ' ':
      prior = -10;
      break;
    case 'n':  //закрывающая скобочка
      prior = -9;
      break;
    case 'u':  // унарный минус
      prior = -8;
      break;
  }
  // if (index == 'x' || index == '.')
  //   prior = 0;
  // else if (index == ')')
  //   prior -1;
  // else if (index == '(')
  //   prior = 1;
  // else if (index == '+' || index == '-')
  //   prior = 2;
  // else if (index == '*' || index == '/')
  //   prior = 3;
  // else if (index == '^' || index == '%')
  //   prior = 4;
  // else if (index == 'e')
  //   prior = 5;
  // else if (index == ' ')
  //   prior = -10;
  // else if (index == 'n') //закрывающая скобочка
  //   prior = -9;
  // else if (index == 'u') // унарный минус
  //   prior = -8;
  return prior;
}
void CalculatorModel::get_function(int &type) {
  double res = stack_result.top();
  stack_result.pop();
  if (type == COS)
    res = cos(res);
  else if (type == SIN)
    res = sin(res);
  else if (type == TAN)
    res = tan(res);
  else if (type == ASIN)
    res = asin(res);
  else if (type == ACOS)
    res = acos(res);
  else if (type == ATAN)
    res = atan(res);
  else if (type == LN)
    res = log(res);
  else if (type == LOG)
    res = log10(res);
  else if (type == SQRT)
    if (res >= 0) res = sqrt(res);
  //   switch (type) {
  //   case COS:
  //     res = cos(res);
  //     break;
  //   case SIN:
  //     res = sin(res);
  //     break;
  //   case TAN:
  //     res = tan(res);
  //     break;
  //   case ASIN:
  //     res = asin(res);
  //     break;
  //   case ACOS:
  //     res = acos(res);
  //     break;
  //   case ATAN:
  //     res = atan(res);
  //     break;
  //   case SQRT:
  //     if (res >= 0) res = sqrt(res);
  //     break;
  //   case LN:
  //     res = log(res);
  //     break;
  //   case LOG:
  //     res = log10(res);
  // }

  stack_result.push(res);
}

int CalculatorModel::get_name_function(std::string &str) {
  int nameFunc = -1;
  if (str == "ln")
    nameFunc = LN;
  else if (str == "sin")
    nameFunc = SIN;
  else if (str == "tan")
    nameFunc = TAN;
  else if (str == "cos")
    nameFunc = COS;
  else if (str == "log")
    nameFunc = LOG;
  else if (str == "acos")
    nameFunc = ACOS;
  else if (str == "asin")
    nameFunc = ASIN;
  else if (str == "atan")
    nameFunc = ATAN;
  else if (str == "sqrt")
    nameFunc = SQRT;
  return nameFunc;
}

bool CalculatorModel::check_function(char str) {
  bool result = false;
  if (str == 'c' || str == 's' || str == 't' || str == 'a' || str == 'l') {
    result = true;
  }
  return result;
}

std::string CalculatorModel::transformation_postfix_notation(std::string &str) {
  bool unar_minus = false;
  for (size_t i = 0; i < str.length(); i++) {
    int j = -1;
    std::string count;
    if (check_function(str[i])) {
      while (str[i] != '(') {
        count += str[i];
        i++;
      }
      current_ += count;
      current_ += ' ';
    }

    int prior = get_priority(str[i]);
    if (prior == 0) {
      current_ += str[i];
    } else if (prior > 1) {
      if (unar_minus) {
        current_ += " u";
        unar_minus = false;
      }
      if ((prior == 2 && str[i] == '-') && (i == 0)) {
        unar_minus = true;
      } else {
        while (!stack_current.empty()) {
          if (get_priority(stack_current.top()) >= prior) {
            current_ += ' ';
            current_ += stack_current.top();
            stack_current.pop();
          } else {
            break;
          }
        }
        current_ += ' ';
        stack_current.push(str[i]);
      }
    } else if (prior == 1) {
      stack_current.push(str[i]);
      i++;
      if (str[i] == '-') {
        unar_minus = true;
      } else {
        i--;
      }

    } else if (prior == -1) {
      while (get_priority(stack_current.top()) != 1) {
        current_ += ' ';
        current_ += stack_current.top();
        stack_current.pop();
      }
      stack_current.pop();
      current_ += ' ';
      current_ += 'n';
    }
  }
  if (unar_minus) {
    current_ += " u";
    unar_minus = false;
  }
  while (!stack_current.empty()) {
    current_ += ' ';
    current_ += stack_current.top();
    stack_current.pop();
  }

  return current_;
}

double CalculatorModel::calculation_result(std::string &str, double &x) {
  std::string converted_str = transformation_postfix_notation(str);
  std::string count;
  int func = 0;
  for (size_t i = 0; i < converted_str.length(); i++) {
    if (check_function(converted_str[i])) {
      while (converted_str[i] != ' ') {
        count += converted_str[i];
        i++;
      }
      func = get_name_function(count);
      count.clear();
    }
    int prior = get_priority(converted_str[i]);
    if (prior == 0) {
      while (converted_str[i] != ' ') {
        count += converted_str[i];
        i++;
      }
      double double_count;
      if (count == "x") {
        double_count = x;
      } else {
        double_count = atof(count.c_str());
      }

      stack_result.push(double_count);
      count.clear();
    } else if (prior == -10) {
      //
    } else if (prior == -9) {
      get_function(func);
      func = 0;
    } else {
      arithmetic_operations(converted_str[i]);
    }
  }
  if (func) {
    get_function(func);
    func = 0;
  }
  double result = stack_result.top();
  stack_result.pop();
  return result;
}
