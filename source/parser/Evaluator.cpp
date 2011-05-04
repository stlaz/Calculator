/**
 * @file   Evaluator.cpp
 * @author Jiri Petruzelka
 * 
 * @brief	interface between parsed entities and math library
 */

#include "Evaluator.h"
#include "../elementaryMath/elementary_math.h"

using namespace std;

namespace CubeSoft {

	namespace Calculator {


		class invalidOperatorException: public exception
		{
		  virtual const char* what() const throw()
		  {
			return "The Item is not literal and therefore do not have a value";
		  }
		} invalidOperatorException;


		double Evaluator::evaluate(Item* value, ItemOperator* op) {
			switch ( (eOperator)op->getValue() ){
				case OP_UNARY_MINUS:
					return value->getValue()*(-1);
				case OP_LOGARITHM:
					return logax(LOG_BASE, value->getValue(), PRECISION );
				case OP_FACTORIAL:
					return (double)factorial( (double)value->getValue() );
				default:
					throw invalidOperatorException;
			}
		}
		
		double Evaluator::evaluate(Item* lvalue, ItemOperator* op, Item* rvalue) {
			switch ( (eOperator)op->getValue() ){
				case OP_PLUS:
					return sum(lvalue->getValue(), rvalue->getValue());
				case OP_MINUS:
					return differ(lvalue->getValue(), rvalue->getValue());
				case OP_DIVIDE:
					return divide(lvalue->getValue(), rvalue->getValue());
				case OP_MULTIPLY:
					return multiply(lvalue->getValue(), rvalue->getValue());
				case OP_POWER:
					return power( lvalue->getValue(), rvalue->getValue() );
				default:
					throw invalidOperatorException;
			}
		}

	}

}

