#include <QApplication>

#include "calculatorView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  //    s21::CalculatorView w;
  //    w.show();
  my::CalculatorModel model;
  my::CalcCreditModel credit_model;
  my::CalculatorController controller(&model, &credit_model);
  my::CalculatorView ma(&controller);
  ma.show();
  return a.exec();
}
