/*
 * @file: calculator.cpp
 * @author: Michal Starigazda
 * login: xstari01
 */

#include "calculator.h"
#include <QtGui>
#include <math.h>
#include "Parser.h"
#include "enums.h"

using namespace CubeSoft::Calculator;

Parser *p = new Parser();

calculator::calculator(QWidget *parent) :
    QDialog(parent)
{
   setupUi(this);

   /**
    * Setting window flags.
    */


   /**
    * Flags inicializations.
    */
   waitingForOperand = true;
   waitingForResult = true;
   unaryOperationAdded = false;

   itemCnt=0;  // counter of items of expression

   /**
    * Lines settings
    */
   lineEdit->setReadOnly(true);
   lineEdit->setAlignment(Qt::AlignRight);
   lineEdit->setMaxLength(25);

   QFont font = lineEdit->font();
   font.setPointSize(font.pointSize() + 8);
   lineEdit->setFont(font);
   lineEdit->setText("0");

   setWindowTitle(tr("Cubesoft Calculator"));

   /**
    * Connecting digit buttons to functions.
    */
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
   } // calculator::calculator

/**
 * Function displays value of clicked digit button.
 * @param digitValue Value ob clicked button.
 */
void calculator::digitClicked(int digitValue)
{   // after unary operator is not allowed another operand
    if (unaryOperationAdded){
        return;
    }

    // Lines are cleared after result if trying add operand
    if (!waitingForResult){
        lineEdit->clear();
        lineShow->clear();
    }

    if (lineEdit->text() == "0" && digitValue == 0.0)
        return;

    if (lineEdit->text() == "#"){
        // after aborted operations is lineEdit set to default
            lineEdit->setText("0");
            waitingForOperand = true;
    }

    if (waitingForOperand) {
        lineEdit->clear();
    waitingForOperand = false;
    waitingForResult = true;
    }

    lineEdit->setText(lineEdit->text() + QString::number(digitValue));
}

/**
 * List of digit clicked functions, each is calling function
 * digitClicked with specific number value
 */
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


/**
 * Functions set point to number if there is not one
 */
void calculator::on_setpoint_clicked()
{
    if (waitingForOperand)
        lineEdit->setText("0");

    if (!lineEdit->text().contains("."))
        lineEdit->setText(lineEdit->text() + tr("."));

    waitingForOperand = false;
}

/**
 * Changing sign of number
 */
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

/**
 * Function cuts out last added character of lineEdit.
 */
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

/**
 * Function clears lineEdit
 */
void calculator::on_clear_clicked()
{
    if (waitingForOperand && lineEdit->text() == "0")
        return;

    lineEdit->setText("0");
    waitingForOperand = true;
}
/**
 * Function clear lineEdit, lineShow, parser inputs,
 * and set item counter to 0.
 */
void calculator::on_clearAll_clicked()
{
    waitingForOperand = true;

    lineEdit->setText("0");
    lineShow->clear();
    p->clearInput();
    itemCnt = 0;
}

/**
 * Sets "#" to lineEdit after illegal input
 */
void calculator::abortOperation()
{
    on_clear_clicked();
    lineEdit->setText(tr("#"));
}

/**
 * Special number button for PI
 */
void calculator::on_pi_clicked()
{
    double pi = 3.141592653589;
    lineEdit->setText(QString::number(pi));
}

/**
 * Display result of input of items added so far.
 */
void calculator::on_equal_clicked()
{
    if (itemCnt == 0){
        waitingForOperand= true;
        return;
    }

    // after unary operations do not add last input on line
    // to parser
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
    }
    else{
        unaryOperationAdded = false;
    }

    lineShow->setText(lineShow->text() + " " + lineEdit->text()+ " " + "=");
    lineEdit->setText(QString::number(p->getValue()));

    waitingForOperand= true;
    waitingForResult = false;

    p = new Parser();

    // set counter to 0
    itemCnt = 0;

}// on_equal_clicked

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser additive operation
 */
void calculator::on_plus_clicked()
{
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
    }
    else{
        unaryOperationAdded = false;
    }

    p->addInput(OP_PLUS);
    itemCnt++;

    lineShow->setText(lineShow->text() + " " + lineEdit->text() + " + ");

    waitingForOperand=true;
    waitingForResult = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser minus operation
 */
void calculator::on_minus_clicked()
{
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
        itemCnt++;
    }
    else{
        unaryOperationAdded = false;
    }

    p->addInput(OP_MINUS);
    itemCnt++;

    lineShow->setText(lineShow->text() + " " + lineEdit->text() + " - ");

    waitingForOperand=true;
    waitingForResult = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser multiply operation
 */
void calculator::on_multiply_clicked()
{
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
        itemCnt++;
    }
    else{
        unaryOperationAdded = false;
    }

    p->addInput(OP_MULTIPLY);
    itemCnt++;

    lineShow->setText(lineShow->text() + " " + lineEdit->text() + " * ");

    waitingForOperand=true;
    waitingForResult = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser divide operation
 */
void calculator::on_divide_clicked()
{
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
        itemCnt++;
    }
    else{
        unaryOperationAdded = false;
    }

    p->addInput(OP_DIVIDE);
    itemCnt++;

    lineShow->setText(lineShow->text() + " " + lineEdit->text() + " / ");

    waitingForOperand=true;
    waitingForResult = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser power operation
 */
void calculator::on_power_clicked()
{
    if (!unaryOperationAdded){
        double operand = lineEdit->text().toDouble();
        p->addInput(operand);
        itemCnt++;
    }
    else{
        unaryOperationAdded = false;
    }

    p->addInput(OP_POWER);
    itemCnt++;

    lineShow->setText(lineShow->text() + " " + lineEdit->text() + "^");

    waitingForOperand = true;
    waitingForResult = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser factorial operation
 * Input is not rewriting to lineShow like binary
 * operations
 */
void calculator::on_factorial_clicked()
{
    if (!waitingForResult){
        lineShow->clear();
    }

    if (unaryOperationAdded){
        p->addInput(OP_FACTORIAL);
        itemCnt++;
    }
    else{
        double operand = lineEdit->text().toDouble();
        p->addInput(operand)->addInput(OP_FACTORIAL);
        itemCnt+=2;
    }

    lineEdit->setText(lineEdit->text() + "!");

    waitingForOperand = true;
    waitingForResult = true;

    unaryOperationAdded = true;
}

/**
 * Function adds input from lineEdit to parser
 * and then adds to parser logarithm (decadic) operation
 * Input is not rewriting to lineShow like binary
 * operations
 */
void calculator::on_logarithm_clicked()
{
    if (!waitingForResult){
        lineShow->clear();
    }

    double operand = lineEdit->text().toDouble();

    if (operand <= 0){
        // invalid input
        abortOperation();
        waitingForOperand = true;
        return;
    }
    else{
    p->addInput(OP_LOGARITHM)->addInput(operand);
    itemCnt++;
    lineEdit->setText("log(" + lineEdit->text() + ")");
    }

    waitingForOperand = false;
    waitingForResult = true;

    unaryOperationAdded = true;
}

/*** End of file calculator.cpp ***/
