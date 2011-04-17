/* 
 * File:   Evaluator.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 20:20
 */

#ifndef EVALUATOR_H
    #define	EVALUATOR_H

#include "enums.h"
#include "Item.h"
#include "ItemOperator.h"

namespace CubeSoft {

	namespace Calculator {

		class Evaluator {
			public:
				static double evaluate(Item *value, ItemOperator *op);
				static double evaluate(Item *lvalue, ItemOperator *op, Item *rvalue);
		};

	}

}

#endif	/* EVALUATOR_H */

