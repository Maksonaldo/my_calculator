#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
#include <QtMath>

#include "calculatorController.h"
#include "qcustomplot.h"

namespace Ui {
class Graph;
}
namespace my {
class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(my::CalculatorController *controller,
                 QWidget *parent = nullptr);
  ~Graph();

 private slots:
  void on_pushButton_exit_clicked();

  void on_pushButton_clear_graph_clicked();

  void on_pushButton_get_graph_clicked();

 private:
  Ui::Graph *ui;
  QString label;
  my::CalculatorController *controller_;
  // CalculatorController controller_;
  void drow_graph();
  void set_style_graph(QCustomPlot *graph, int tan);
  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;

 public slots:
  void slott(QString a);
};
}  // namespace my
#endif  // GRAPH_H
