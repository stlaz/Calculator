/* 
 * File:   ItemOperator.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 20:04
 */

#ifndef ITEMOPERATOR_H
#define	ITEMOPERATOR_H

#include "enums.h"
#include "Item.h"


namespace CubeSoft {

	namespace Calculator {

		class ItemOperator: public Item {
			public:
				ItemOperator(Item *item);
				ItemOperator(eOperator op);

				eType getType();
				double getValue();
				eArgs getArgs();
				string getAsString();
			private:
				eOperator op;
		};

	}

}

#endif	/* ITEM_H */
