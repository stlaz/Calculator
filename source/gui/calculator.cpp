#include "calculator.h"
#include <QtGui>
#include <math.h>
#include "Parser.h"
#include "enums.h"
using namespace CubeSoft::Calculator;
Parser *p = new Parser();
QString OPSign = NULL;
bool resultGiven = true;

calculator::calculator(QWidget *parent) :
    QDialog(parent)
{
   setupUi(this);

   Qt::WindowFlags flags;
   flags = Qt::Window | Qt::WindowMinimizeButtonHint;
   setWindowFlags( flags );

   waitingForOperand = true;


   lineEdit->setReadOnly(true);
   lineEdit->setAlignment(Qt::AlignRight);
   lineEdit->setMaxLength(15);

   QFont font = lineEdit->font();
   font.setPointSize(font.pointSize() + 8);
   lineEdit->setFont(font);
   lineEdit->setText("0");

   setWindowTitle(tr("Cubesoft::Calculator"));

   connect( digit0, SIGNAL( clicked() ), this, SLOT( digitClicked0() ) );
   connect( digit1, SIGNAL( clicked() ), this, SLOT( digitClicked1() ) );
   connect( digit2, SIGNAL( clicked() ), this, SLOT( digitClicked2() ) );
   connect( digit3, SIGNAL( clicked() ), this, SLOT( digitClicked3() ) );
   connect( digit4, SIGNAL( clicked() ), this, SLOT( digitClicked4() ) );
   connect( digit5, SIGNAL( clicked() ), this, SLOT( digitClicked5() ) );
   connect( digit6, SIGNAL( clicked() ), this, SLOT( digitClicked6() ) );
   connect( digit7, SIGNAL( clicked() ), this, SLOT( digitClicked7() ) );
   connect( digit8, SIGNAL( clicked() ), this, SLOT( digitClicked8() ) );
   connect( digit9, SIGNAL( clicked() ), this, SLOT( digitClicked9() ) );
   }

void calculator::digitClicked(int digitValue)
{
    if (lineEdit->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        if (lineEdit->text() != "0" ){
            lineShow->setText(lineShow->text() + " " + lineEdit->text() + OPSign);}
        lineEdit->clear();
    waitingForOperand = false;
    }
    lineEdit->setText(lineEdit->text() + QString::number(digitValue));
}

void calculator::digitClicked0(){digitClicked(0);}
void calculator::digitClicked1(){digitClicked(1);}
void calculator::digitClicked2(){digitClicked(2);}
void calculator::digitClicked3(){digitClicked(3);}
void calculator::digitClicked4(){digitClicked(4);}
void calculator::digitClicked5(){digitClicked(5);}
void calculator::digitClicked6(){digitClicked(6);}
void calculator::digitClicked7(){digitClicked(7);}
void calculator::digitClicked8(){digitClicked(8);}
void calculator::digitClicked9(){digitClicked(9);}

void calculator::on_setpoint_clicked()
{
    if (waitingForOperand)
        lineEdit->setText("0");
    if (!lineEdit->text().contains("."))
        lineEdit->setText(lineEdit->text() + tr("."));
    waitingForOperand = false;
}

void calculator::on_changeSign_clicked()
{
    QString text = lineEdit->text();
    double value = text.toDouble();

    if (value > 0.0) {
       text.prepend(tr("-"));
    } else if (value < 0.0) {
         text.remove(0, 1);
    }
    lineEdit->setText(text);
}

void calculator::on_backspace_clicked()
{
    if (waitingForOperand)
        return;

    QString text = lineEdit->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    lineEdit->setText(text);
}

void calculator::on_clear_clicked()
{
    if (waitingForOperand && lineEdit->text() == "0")
        return;

    lineEdit->setText("0");
    waitingForOperand = true;
}

void calculator::on_pi_clicked()
{
    double pi = 3.141592653589;
    lineEdit->setText(QString::number(pi));
}

void calculator::on_plus_clicked()
{
    double operand = lineEdit->text().toDouble();
    p->addInput(operand)->addInput(OP_PLUS);
    OPSign = "+" ;
    waitingForOperand=true;
}

void calculator::on_equal_clicked()
{
    double operand = lineEdit->text().toDouble();
    p->addInput(operand);
    double result = p->getRoot()->getValue();
    p->clearInput()->addInput(result);
    lineEdit->setText(QString::number(result));
    waitingForOperand=true;
    resultGiven = true;
}


void calculator::on_clear_2_clicked()
{
    waitingForOperand = true;
    lineEdit->setText("0");
    lineShow->clear();
    p->clearInput();
}
