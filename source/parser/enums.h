/* 
 * File:   enums.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 17:25
 */

#ifndef ENUMS_H
    #define	ENUMS_H

namespace CubeSoft {

    namespace Calculator {

        typedef enum eOperator {
            OP_PLUS,
            OP_MINUS,
			OP_UNARY_MINUS,
            OP_DIVIDE,
            OP_MULTIPLY,
            OP_POWER,
            OP_FACTORIAL,
            OP_LOGARITHM
        } eOperator;


        typedef enum eType {
            T_LITERAL,
            T_OPERATOR,
            T_EXPRESSION
        } eType;


		typedef enum eArgs {
			A_NONE,
			A_UNARY_LEFT,
			A_UNARY_RIGHT,
			A_BINARY
		} eArgs;
			


		const eArgs table[] = {
			A_BINARY,
			A_BINARY,
			A_UNARY_LEFT,
			A_BINARY,
			A_BINARY,
			A_BINARY,
			A_UNARY_RIGHT,
			A_UNARY_LEFT
		};


		const char signs[][4] = {
			"+",
			"-",
			"-",
			"/",
			"*",
			"^",
			"!",
			"log"
		};

    }
}


#endif	/* ENUMS_H */

