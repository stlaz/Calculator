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
    ../../parser/Parser.cpp \
    ../../parser/ItemOperator.cpp \
    ../../parser/ItemLiteral.cpp \
    ../../parser/ItemExpression.cpp \
    ../../parser/Item.cpp \
    ../../parser/Evaluator.cpp \
    ../../elementaryMath/elementary_math.cpp

HEADERS  += calculator.h \   
    ../../parser/Parser.h \
    ../../parser/ItemOperator.h \
    ../../parser/ItemLiteral.h \
    ../../parser/ItemExpression.h \
    ../../parser/Item.h \
    ../../parser/Evaluator.h \
    ../../parser/enums.h \
    ../../elementaryMath/elementary_math.h

FORMS    += calculator.ui
