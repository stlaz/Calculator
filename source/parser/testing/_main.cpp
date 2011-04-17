/* 
 * File:   evaluator.cpp
 * Author: Nox
 *
 * Created on 18. březen 2011, 16:43
 */

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Parser.h"
#include "enums.h"

#define DEBUG 0

using namespace std;
using namespace CubeSoft::Calculator;

int main(int argc, char** argv) {

	Parser *p = new Parser();

	   p->addInput(OP_UNARY_MINUS)
		->addInput(9)
		->addInput(OP_PLUS)
		->addInput(OP_LOGARITHM)
		->addInput((double)(M_E*M_E*M_E))
		->addInput(OP_FACTORIAL)
	    ->addInput(OP_MULTIPLY)
	    ->clearInput()						/* clear input ! */
		->addInput(2)
		->addInput(OP_PLUS)
		->addInput(-4)
		->addInput(OP_MULTIPLY)
		->addInput(2)
		->addInput(OP_FACTORIAL);

	cout << p->getRoot()->getAsString() << " = " << p->getRoot()->getValue() << endl;

    return 0;
}

