/* 
 * File:   ItemExpression.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 20:06
 */

#include <cstddef>
#include "ItemExpression.h"
#include "Evaluator.h"

using namespace std;

namespace CubeSoft {

	namespace Calculator {

		ItemExpression::ItemExpression(ItemOperator *op, Item *rvalue) {
			this->lvalue	= NULL;
			this->op		= op;
			this->rvalue	= rvalue;
		}
		
		
		ItemExpression::ItemExpression(Item *lvalue, ItemOperator *op, Item *rvalue) {
			this->lvalue	= lvalue;
			this->op		= op;
			this->rvalue	= rvalue;
		}


		double ItemExpression::getValue() {
			if( this->lvalue == NULL )
				return Evaluator::evaluate(this->rvalue, this->op);
			else
				return Evaluator::evaluate(this->lvalue, this->op, this->rvalue);
		}

		eType ItemExpression::getType() {
			return T_EXPRESSION;
		}
		
		string ItemExpression::getAsString() {
			if( this->lvalue == NULL )
			{
				if( this->op->getArgs() == A_UNARY_LEFT )
					return string( this->op->getAsString() + this->rvalue->getAsString() );
				else
					return string( this->rvalue->getAsString() + this->op->getAsString() );
			}
			else
				return string( this->lvalue->getAsString() + this->op->getAsString() + this->rvalue->getAsString() );
		}

	}

}