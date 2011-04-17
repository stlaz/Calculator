/* 
 * File:   Item.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 17:47
 */

#ifndef ITEM_H
#define	ITEM_H

#include "enums.h"
#include <exception>
#include <string>

using std::exception;
using std::string;

namespace CubeSoft {

    namespace Calculator {

        class Item {
            public:				
				virtual double getValue();
				virtual eType getType();
				virtual eArgs getArgs();
				virtual string getAsString();
        };

    }

}

#endif	/* ITEM_H */

