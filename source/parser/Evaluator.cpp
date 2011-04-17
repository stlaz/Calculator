/* 
 * File:   Evaluator.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 20:20
 */

#include "Evaluator.h"
#include "elementary_math.h"
#include <math.h>

using namespace std;

namespace CubeSoft {

	namespace Calculator {

		int fact(int number) {
			int temp;

			if(number <= 1) return 1;

			temp = number * fact(number - 1);
			return temp;
		}

		class invalidOperatorException: public exception
		{
		  virtual const char* what() const throw()
		  {
			return "The Item is not literal and therefore do not have a value";
		  }
		} invalidOperatorException;

		/**
		 * @todo FINISH!!!
         */

		double Evaluator::evaluate(Item* value, ItemOperator* op) {
			switch ( (eOperator)op->getValue() ){
				case OP_UNARY_MINUS:
					return value->getValue()*(-1);
				case OP_LOGARITHM:
					return log( value->getValue() );
				case OP_FACTORIAL:
					return fact( value->getValue() );
				default:
					throw invalidOperatorException;
			}
		}
		
		double Evaluator::evaluate(Item* lvalue, ItemOperator* op, Item* rvalue) {
			switch ( (eOperator)op->getValue() ){
				case OP_PLUS:
					return lvalue->getValue() + rvalue->getValue();
				case OP_MINUS:
					return lvalue->getValue() - rvalue->getValue();
				case OP_DIVIDE:
					return lvalue->getValue() / rvalue->getValue();
				case OP_MULTIPLY:
					return lvalue->getValue() * rvalue->getValue();
				case OP_POWER:
					return pow( lvalue->getValue(), rvalue->getValue() );
				default:
					throw invalidOperatorException;
			}
		}

	}

}

