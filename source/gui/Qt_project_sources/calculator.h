/*
 * @ile: calculator.h
 * @author: Michal Starigazda
 *
 * login: xstari01
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ui_calculator.h"
#include <Parser.h>
#include <enums.h>

namespace Ui {
    class calculator;
}

class calculator : public QDialog, private Ui::calculator
{
    Q_OBJECT

public:
    calculator(QWidget *parent = 0);

private slots:
    void on_logarithm_clicked();
    void on_factorial_clicked();
    void on_power_clicked();
    void on_divide_clicked();
    void on_multiply_clicked();
    void on_minus_clicked();
    void on_clearAll_clicked();
    void on_equal_clicked();
    void on_plus_clicked();
    void on_pi_clicked();
    void on_clear_clicked();
    void on_backspace_clicked();
    void on_changeSign_clicked();
    void on_setpoint_clicked();
    void digitClicked(int digitValue);
    void digitClicked0();
    void digitClicked1();
    void digitClicked2();
    void digitClicked3();
    void digitClicked4();
    void digitClicked5();
    void digitClicked6();
    void digitClicked7();
    void digitClicked8();
    void digitClicked9();
    void abortOperation();

private:
    bool waitingForOperand;
    bool waitingForResult;
    bool unaryOperationAdded;
    int itemCnt;
};

#endif // CALCULATOR_H

/*** End of file calculator.h ***/
