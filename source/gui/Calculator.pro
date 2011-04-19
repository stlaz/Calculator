#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T20:37:29
#
#-------------------------------------------------

QT       += core gui

TARGET = Calculator
TEMPLATE = app


SOURCES +=\
        calculator.cpp main.cpp \
    Parser.cpp \
    ItemOperator.cpp \
    ItemLiteral.cpp \
    ItemExpression.cpp \
    Item.cpp \
    Evaluator.cpp \
    ../parser/Parser.cpp \
    ../parser/ItemOperator.cpp \
    ../parser/ItemLiteral.cpp \
    ../parser/ItemExpression.cpp \
    ../parser/Item.cpp \
    ../parser/Evaluator.cpp

HEADERS  += calculator.h \ 
    Parser.h \
    ItemOperator.h \
    ItemLiteral.h \
    ItemExpression.h \
    Item.h \
    Evaluator.h \
    enums.h \
    ../parser/Parser.h \
    ../parser/ItemOperator.h \
    ../parser/ItemLiteral.h \
    ../parser/ItemExpression.h \
    ../parser/Item.h \
    ../parser/Evaluator.h \
    ../parser/enums.h

FORMS    += calculator.ui
