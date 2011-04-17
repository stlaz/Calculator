/*
 * File:   ItemLiteral.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 17:47
 */

#ifndef ITEMLITERAL_H
    #define	ITEMLITERAL_H

#include "enums.h"
#include "Item.h"


namespace CubeSoft {

    namespace Calculator {

        class ItemLiteral: public Item {
            public:
                ItemLiteral(double value);

				eType getType();
                double getValue();
				string getAsString();
            private:
                double value;
        };
        
    }

}

#endif	/* ITEM_H */

