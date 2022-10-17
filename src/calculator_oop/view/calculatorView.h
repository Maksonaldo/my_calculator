#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include <QMainWindow>

#include "QValidator"
#include "calcCreditView.h"
#include "calculatorController.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatorView;
}
QT_END_NAMESPACE

namespace my {
class CalculatorView : public QMainWindow {
  Q_OBJECT

 public:
  CalculatorView(my::CalculatorController *controller,
                 QWidget *parent = nullptr);
  ~CalculatorView();

 private:
  Ui::CalculatorView *ui;
  Graph *graph_;
  my::CalculatorController *controller_;
  CalcCreditView *credit_;
  int count_left = -1;
  int count_rigth = 0;
  int size_point = 0;

  void bool_point(bool point);
  void bool_bracket_right(bool point);
  void bool_bracket_left(bool point);
  void bool_numbers(bool point);
  void bool_operators(bool point);
  void bool_functions(bool point);
  void bool_exp(bool point);
 private slots:
  void show_e();
  void show_numbers();
  void show_function();
  void show_operators();

  void on_pushButton_equal_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_clear_clicked();

  void show_bracket();
  void on_pushButton_credit_clicked();
 signals:
  void signal(QString);
};

}  // namespace my

#endif  // CALCULATORVIEW_H
