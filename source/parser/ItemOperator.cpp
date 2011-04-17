/* 
 * File:   ItemOperator.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 20:04
 */

#include "ItemOperator.h"

using namespace std;

namespace CubeSoft {

	namespace Calculator {

		ItemOperator::ItemOperator(Item* item) {
			this->op = (eOperator)item->getValue();
		}

		ItemOperator::ItemOperator(eOperator op) {
			this->op = op;
		}


		double ItemOperator::getValue() {
			return (double)this->op;
		}

		eType ItemOperator::getType() {
			return T_OPERATOR;
		}

		eArgs ItemOperator::getArgs() {
			return table[ this->op ];
		}

		string ItemOperator::getAsString() {
			return string( signs[ (eOperator)this->getValue() ] );
		}

	}

}