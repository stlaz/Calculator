/* 
 * File:   ItemExpression.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 20:06
 */

#ifndef ITEMEXPRESSION_H
    #define	ITEMEXPRESSION_H

#include "enums.h"
#include "Item.h"
#include "ItemOperator.h"


namespace CubeSoft {

    namespace Calculator {

        class ItemExpression: public Item {
            public:
                ItemExpression(ItemOperator *op, Item *rvalue);
                ItemExpression(Item *lvalue, ItemOperator *op, Item *rvalue);

				eType getType();
                double getValue();
				string getAsString();
            private:
                Item *lvalue;
                ItemOperator *op;
                Item *rvalue;
        };

    }

}

#endif	/* ITEM_H */
