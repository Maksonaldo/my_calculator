#ifndef CALCCREDITVIEW_H
#define CALCCREDITVIEW_H

#include <QWidget>

#include "calculatorController.h"

namespace Ui {
class CalcCreditView;
}
namespace my {
class CalcCreditView : public QWidget {
  Q_OBJECT

 public:
  explicit CalcCreditView(CalculatorController *controller,
                          QWidget *parent = nullptr);
  ~CalcCreditView();
 private slots:
  void on_pushButton_close_clicked();

  void on_pushButton_result_clicked();

 private:
  Ui::CalcCreditView *ui;
  CalculatorController *controller_;
};
}  // namespace my

#endif  // CALCCREDITVIEW_H
