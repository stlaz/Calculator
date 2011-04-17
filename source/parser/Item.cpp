/* 
 * File:   Item.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 17:47
 */

#include "Item.h"

using namespace std;

namespace CubeSoft {

	namespace Calculator {

		eType Item::getType() {
			return T_EXPRESSION;
		}

		double Item::getValue() {
			return 0;
		}

		eArgs Item::getArgs() {
			return A_NONE;
		}

		string Item::getAsString() {
			return string("");
		}

		/**
         * Exception thrown when trying to acquire value of an object that is in state
         * in which it cannot contain a value
         */
        class noValueException: public exception
        {
          virtual const char* what() const throw()
          {
            return "The Item is not literal and therefore do not have a value";
          }
        };


        /**
         * Exception thrown when trying to acquire operator or operand of an
         * object in a literal state
         */
        class isNotExpressionException: public exception
        {
          virtual const char* what() const throw()
          {
            return "The Item is not expression";
          }
        };

	}

}