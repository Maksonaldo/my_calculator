#include "calculatorView.h"

#include "./ui_calculatorView.h"
using my::CalculatorView;

CalculatorView::CalculatorView(my::CalculatorController *controller,
                               QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorView), controller_(controller) {
  ui->setupUi(this);
  credit_ = new CalcCreditView(controller_);
  graph_ = new Graph(controller_, this);

  connect(this, &CalculatorView::signal, graph_, &Graph::slott);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(show_numbers()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(show_numbers()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(show_function()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(show_function()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(show_operators()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(show_operators()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(show_operators()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(show_operators()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(show_operators()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(show_operators()));
  //скобки
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(show_bracket()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(show_bracket()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(show_numbers()));

  connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(show_e()));

  ui->lineEdit_x->setValidator(
      new QDoubleValidator(-10000000000, 10000000000, 6));

  bool_point(true);
  bool_bracket_right(true);
  bool_operators(true);
  bool_exp(true);
}

CalculatorView::~CalculatorView() {
  delete ui;
  delete graph_;
  delete credit_;
}
void CalculatorView::bool_point(bool point) {
  ui->pushButton_point->blockSignals(point);
}
void CalculatorView::bool_bracket_right(bool point) {
  ui->pushButton_right_bracket->blockSignals(point);
}
void CalculatorView::bool_bracket_left(bool point) {
  ui->pushButton_left_bracket->blockSignals(point);
}
void CalculatorView::bool_exp(bool point) {
  ui->pushButton_e->blockSignals(point);
}
void CalculatorView::bool_numbers(bool point) {
  ui->pushButton_1->blockSignals(point);
  ui->pushButton_2->blockSignals(point);
  ui->pushButton_3->blockSignals(point);
  ui->pushButton_4->blockSignals(point);
  ui->pushButton_5->blockSignals(point);
  ui->pushButton_6->blockSignals(point);
  ui->pushButton_7->blockSignals(point);
  ui->pushButton_8->blockSignals(point);
  ui->pushButton_9->blockSignals(point);
}
void CalculatorView::bool_operators(bool point) {
  ui->pushButton_plus->blockSignals(point);
  ui->pushButton_minus->blockSignals(point);
  ui->pushButton_div->blockSignals(point);
  ui->pushButton_mod->blockSignals(point);
  ui->pushButton_pow->blockSignals(point);
  ui->pushButton_mul->blockSignals(point);
}
void CalculatorView::bool_functions(bool point) {
  ui->pushButton_sin->blockSignals(point);
  ui->pushButton_asin->blockSignals(point);
  ui->pushButton_cos->blockSignals(point);
  ui->pushButton_acos->blockSignals(point);
  ui->pushButton_tan->blockSignals(point);
  ui->pushButton_atan->blockSignals(point);
  ui->pushButton_ln->blockSignals(point);
  ui->pushButton_log->blockSignals(point);
  ui->pushButton_sqrt->blockSignals(point);
}

void CalculatorView::show_bracket() {
  bool_bracket_right(false);
  bool_point(true);

  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label_result->text() + button->text();
  if (button->text() == "(") {
    bool_functions(false);
    bool_operators(false);
    bool_numbers(false);
    count_left++;
  } else if (button->text() == ")") {
    bool_numbers(true);
    count_rigth++;
  }
  if (count_left < count_rigth) {
    bool_bracket_right(true);
  } else {
    bool_bracket_right(false);
  }
  ui->label_result->setText(new_label);
}

void CalculatorView::show_numbers() {
  bool_operators(false);
  bool_exp(false);
  bool_point(false);
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label_result->text() + button->text();
  ui->label_result->setText(new_label);
  if (button->text() == ".") {
    size_point++;
  }
  if (size_point > 0) {
    bool_point(true);
  }
  bool_bracket_left(true);
  bool_functions(true);
  qDebug() << size_point;
}

void CalculatorView::show_function() {
  bool_point(true);
  bool_functions(true);
  bool_bracket_right(true);
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label_result->text() + button->text();
  ui->label_result->setText(new_label);
  bool_operators(true);
  bool_numbers(true);
}
void CalculatorView::show_operators() {
  bool_numbers(false);
  bool_bracket_left(false);
  size_point = 0;
  QPushButton *button = (QPushButton *)sender();
  QString new_label;

  if (button->text() == "mod") {
    new_label = ui->label_result->text() + '%';
  } else {
    new_label = ui->label_result->text() + button->text();
  }
  ui->label_result->setText(new_label);
  bool_point(true);
  bool_operators(true);
  bool_functions(false);
}
void CalculatorView::show_e() {
  bool_bracket_left(false);
  bool_operators(true);
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label_result->text() + button->text();
  ui->label_result->setText(new_label);
}

void CalculatorView::on_pushButton_equal_clicked() {
  QString input, new_label;
  double result = 0;
  input = ui->label_result->text();
  if (input.endsWith('(') || input.endsWith('*') || input.endsWith('+') ||
      input.endsWith('-') || input.endsWith('/') || input.endsWith('^') ||
      input.endsWith('%') || (input.length() == 0) || input.endsWith('.') ||
      (count_left == count_rigth)) {
  } else {
    std::string tmp = input.toStdString();
    double x = ui->lineEdit_x->text().toDouble();
    result = controller_->calculation_result(tmp, x);
    new_label = QString::number(result, 'g', 15);
    ui->label_result->setText(new_label);
  }
}

void CalculatorView::on_pushButton_graph_clicked() {
  emit signal(ui->label_result->text());
  graph_->show();
}

void CalculatorView::on_pushButton_clear_clicked() {
  count_left = -1;
  count_rigth = 0;
  size_point = 0;
  bool_point(true);
  bool_point(true);
  bool_bracket_left(false);
  bool_bracket_right(true);
  bool_operators(true);
  bool_functions(false);
  bool_numbers(false);
  bool_exp(true);
  ui->label_result->setText("");
}

void CalculatorView::on_pushButton_credit_clicked() { credit_->show(); }
