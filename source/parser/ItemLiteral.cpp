/* 
 * File:   ItemLiteral.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 19:59
 */

#include "ItemLiteral.h"
#include <sstream>

using namespace std;

namespace CubeSoft {

	namespace Calculator {

		ItemLiteral::ItemLiteral(double value) {
			this->value = value;
		}

		
		double ItemLiteral::getValue() {
			return this->value;
		}

		eType ItemLiteral::getType() {
			return T_LITERAL;
		}

		string ItemLiteral::getAsString() {
			stringstream s;
			s << this->value;

			return string( s.str() );
		}

	}

}