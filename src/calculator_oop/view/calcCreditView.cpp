#include "calcCreditView.h"

#include "ui_calcCreditView.h"

using my::CalcCreditView;
CalcCreditView::CalcCreditView(CalculatorController *controller,
                               QWidget *parent)
    : QWidget(parent), ui(new Ui::CalcCreditView), controller_(controller) {
  ui->setupUi(this);
  ui->lineEdit_all_sum->setValidator(new QDoubleValidator(0, 10000000000, 6));
  ui->lineEdit_credit_term->setValidator(new QIntValidator(0, 10000));
  ui->lineEdit_interest_rate->setValidator(new QIntValidator(0, 1000));
}

CalcCreditView::~CalcCreditView() { delete ui; }

void CalcCreditView::on_pushButton_close_clicked() { close(); }

void CalcCreditView::on_pushButton_result_clicked() {
  QString QP, Qoverpayment, QobshSum, Sum;
  double overpayment, platej;
  double sum_credit = ui->lineEdit_all_sum->text().toDouble();
  //  процентная ставка
  double interset_rate = ui->lineEdit_interest_rate->text().toDouble();
  //  срок
  double term = ui->lineEdit_credit_term->text().toDouble();
  double obshSum = 0;
  if (ui->comboBox_type->currentText() == "Аннуитетный") {
    ui->label_mouth->hide();
    ui->label_point->hide();
    //  Ежемесячный платеж;
    platej = controller_->calc_credit_aut(sum_credit, term, interset_rate);
    //  Переплата
    overpayment = controller_->overment_aut(platej, term, sum_credit);
    //  общая сумма выплат
    obshSum = controller_->sum_aut(overpayment, sum_credit);
  } else {
    double sum_credit_2 = sum_credit;
    ui->label_mouth->show();
    ui->label_point->show();
    platej =
        controller_->calc_credit_def_start(sum_credit, term, interset_rate);
    obshSum = controller_->calc_credit_def(sum_credit, term, interset_rate);
    qDebug() << obshSum << "\n";
    qDebug() << sum_credit << "\n";
    overpayment = controller_->overment_def(obshSum, sum_credit_2);
    Sum = QString::number(sum_credit, 'f', 2);
    ui->label_mouth->setText(Sum);
  }
  //  Ежемесячный платеж;
  QP = QString::number(platej, 'f', 2);
  ui->label_all_sum->setText(QP);
  //  Переплата
  Qoverpayment = QString::number(overpayment, 'f', 2);
  ui->label_credit_term->setText(Qoverpayment);
  //  общая сумма выплат
  QobshSum = QString::number(obshSum, 'f', 2);
  ui->label_interest_rate->setText(QobshSum);
}
