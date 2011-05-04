/**
 * @file   Evaluator.cpp
 * @author Jiri Petruzelka
 * 
 * @brief	interface between parsed entities and math library
 */

#ifndef EVALUATOR_H
    #define	EVALUATOR_H

#include "enums.h"
#include "Item.h"
#include "ItemOperator.h"

#define LOG_BASE 10
#define PRECISION 8

namespace CubeSoft {

	namespace Calculator {

		class Evaluator {
			public:
				/**
				 * @param *value value
				 * @param *op unary operator
				 */
				static double evaluate(Item *value, ItemOperator *op);

				/**
				 * @param *value value
				 * @param *op unary operator
				 */
				static double evaluate(Item *lvalue, ItemOperator *op, Item *rvalue);
		};

	}

}

#endif	/* EVALUATOR_H */

