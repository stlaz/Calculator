#include <QtGui/QApplication>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    calculator window;
    window.show();

    return app.exec();
}
