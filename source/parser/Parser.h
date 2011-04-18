/* 
 * File:   Parser.h
 * Author: Nox
 *
 * Created on 18. březen 2011, 16:53
 */

#ifndef PARSER_H
	#define	PARSER_H

#include <map>
#include <vector>
#include <string>
#include "enums.h"
#include "Item.h"
#include "Evaluator.h"

using namespace std;

namespace CubeSoft {

    namespace Calculator {

		typedef vector<Item*>::iterator itemIterator;

        class Parser {
            public:
                Parser();

				Parser* addInput(double value);
				Parser* addInput(eOperator op);
                Parser* addInput(Item* item);
				Parser* clearInput();
				
				void buildTree();
				Item* getRoot();
				double getValue();
            private:
                void close();

				Item* root;
                vector<Item*> input;

                static map<eOperator, int> createPrecedencyTable();
                static const map<eOperator, int> precedencyTable;

				Item* getNextOfType(itemIterator iter, itemIterator end, eType type);
				itemIterator addItem(Item *starter, itemIterator iter);
        };        
        
    }

}

#endif	/* PARSER_H */

