#include "graph.h"

#include "ui_graph.h"
using my::Graph;

Graph::Graph(CalculatorController *controller, QWidget *parent)
    : QDialog(parent), ui(new Ui::Graph), controller_(controller) {
  ui->setupUi(this);
  ui->spinBox_set_x_max->setValue(10);
  ui->spinBox_set_x_min->setValue(-10);
  ui->spinBox_set_y_max->setValue(4);
  ui->spinBox_set_y_min->setValue(-4);
}

Graph::~Graph() { delete ui; }
void Graph::set_style_graph(QCustomPlot *graph, int tan) {
  graph->xAxis->setBasePen(QPen(QColor(
      "#3399ff")));  // Горизонтальные и вертикальные линии оси координат X
  graph->yAxis->setBasePen(QPen(QColor(
      "#3399ff")));  // Горизонтальные и вертикальные линии оси координат Y

  graph->xAxis->setTickPen(
      QPen(QColor("#ff66ff")));  // Цвет маленькой галочки над числом на оси X
  graph->yAxis->setTickPen(
      QPen(QColor("#ff66ff")));  // Цвет маленькой галочки над числом на оси Y

  graph->xAxis->setTickLabelColor(QColor("#ff66ff"));  // Число на оси X
  graph->yAxis->setTickLabelColor(QColor("#ff66ff"));  // Число на оси Y

  graph->xAxis->setUpperEnding(
      QCPLineEnding::esSpikeArrow);  // Cтрелки на оси координат X
  graph->yAxis->setUpperEnding(
      QCPLineEnding::esSpikeArrow);  // Cтрелки на оси координат Y
  graph->xAxis->setSubTickPen(QPen(
      QColor("#ff66ff")));  // Цвет мелкой шкалы и конечной стрелки на оси X
  graph->yAxis->setSubTickPen(QPen(
      QColor("#ff66ff")));  // Цвет мелкой шкалы и конечной стрелки на оси Y

  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(32, 31, 55));
  plotGradient.setColorAt(1, QColor(32, 34, 53));
  graph->axisRect()->setBackground(plotGradient);  // Цвет фона графика

  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(30, 35, 55));
  axisRectGradient.setColorAt(1, QColor(30, 40, 50));
  graph->setBackground(axisRectGradient);  // Цвет заднего плана

  for (int i = 0; i < graph->graphCount(); i++) {
    if (!tan) {
      graph->graph(i)->setPen(
          QPen(QColor("#ff0000")));  // Цвет кисти для рисования кривой
    } else {
      graph->graph(i)->setLineStyle(QCPGraph::lsNone);
      graph->graph(i)->setScatterStyle(
          QCPScatterStyle(QCPScatterStyle::ssDisc, QColor("#ff0000"), 2));
    }
  }
  graph->setInteraction(QCP::iRangeZoom, true);  // Zoom
  graph->setInteraction(QCP::iRangeDrag, true);  // Scroll
}

void Graph::drow_graph() {
  QCustomPlot *graph = ui->widget;
  double Xmax = ui->spinBox_set_x_max->value();
  double Xmin = ui->spinBox_set_x_min->value();
  double Ymax = ui->spinBox_set_y_max->value();
  double Ymin = ui->spinBox_set_y_min->value();
  if (Xmin < Xmax)
    graph->xAxis->setRange(Xmin, Xmax);  // Текущий диапазон отображения оси X
  graph->yAxis->setRange(Ymin, Ymax);  // Текущий диапазон отображения оси X
  int i = 0;
  h = (abs(Xmin) + abs(Xmax)) / 1000;
  graph->addGraph();
  QString input;
  input = label;
  qDebug() << label;
  if (input.isEmpty()) {
  } else {
    std::string tmp = input.toStdString();
    for (X = Xmin; X <= Xmax; X += h) {
      double result = controller_->calculation_result(tmp, X);
      qDebug() << " --> " << result;
      if (!std::isnan(result) && result > -1e6 && result < 1e6) {
        x.push_back(X);
        y.push_back(result);
      }
    }
  }

  set_style_graph(graph, 1);  //стиль
  graph->graph(i++)->setData(x, y);
  graph->replot();
}
void Graph::on_pushButton_exit_clicked() { close(); }

void Graph::on_pushButton_clear_graph_clicked() {
  ui->widget->clearGraphs();
  ui->widget->replot();
}
void Graph::on_pushButton_get_graph_clicked() { drow_graph(); }
void Graph::slott(QString a) { label = a; }
