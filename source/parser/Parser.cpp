/* 
 * File:   Parser.cpp
 * Author: Nox
 * 
 * Created on 18. březen 2011, 16:53
 */

#include <iostream>
#include "Parser.h"
#include "enums.h"
#include "ItemLiteral.h"
#include "ItemOperator.h"
#include "ItemExpression.h"

using namespace std;

namespace CubeSoft {

	namespace Calculator {
		
		/**
		 * Constant precedency table
		 */
		const map<eOperator, int> Parser::precedencyTable = Parser::createPrecedencyTable();

		Parser::Parser() {
			this->root   = NULL;
		}



		/**
		 * Adds the input to the end of the input buffer
		 * Must not be closed!
		 *
         * @param Item* item
		 * @return Parser*	providing fluid interface
         */
		Parser* Parser::addInput(Item* item) {
			this->input.push_back( item );

			return this;
		}


		/**
		 * Removes all input passed so far, allowing to request parsing of another equation
		 * 
         * @return Parser*	providing fluid interface
         */
		Parser* Parser::clearInput() {
			vector<Item*>::iterator inputI;

			for( inputI = this->input.begin(); inputI != this->input.end(); inputI++ )
				delete *inputI;

			this->input.clear();

			this->root = NULL;

			return this;
		}

		
		/**
		 * Adds simple literal value
		 * 
         * @param value
         * @return Parser*	providing fluid interface
         */
		Parser* Parser::addInput(double value) {
			ItemLiteral *item = new ItemLiteral(value);
			
			this->input.push_back( item );

			return this;
		}

		
		/**
		 * Adds operator based on the identifying enum item
		 * 
         * @param eOperator operator
         * @return Parser*	providing fluid interface
         */
		Parser* Parser::addInput(eOperator op) {
			ItemOperator *item = new ItemOperator(op);
			
			this->input.push_back( item );

			return this;
		}



		/**
		 * Internal function, returns next item in the sequence matching given type
		 *
         * @param iter
         * @param end
         * @param type
         * @return Item*
         */
		Item* Parser::getNextOfType(itemIterator iter, itemIterator end, eType type)
		{
			for(iter++ ; iter != end; iter++ )
			{
				if( (*iter)->getType() == type )
					return *iter;
			}

			return NULL;
		}


		/**
		 * Turns a sequence of 2-3 (binary X unary operator) items into a tree of items,
		 * replacing it with 1 expression in the sequence,
		 * setting it as the root
		 *
         * @param starter
         * @param iter
         * @return itemIterator
         */
		itemIterator Parser::addItem(Item* starter, itemIterator iter) {
			ItemExpression *item;
			
			if( starter->getArgs() == A_NONE )
				return iter;
			
			ItemOperator *iOperator = new ItemOperator(starter);

			if( starter->getArgs() == A_BINARY )
			{
				item = new ItemExpression(
					// previous
					*(iter-1),
					// this (OPERATOR),
					iOperator,
					//next
					*(iter+1)
				);

				// replace in the input
				iter = this->input.erase(iter-1, iter+2);
			}
			else if( starter->getArgs() == A_UNARY_RIGHT )
			{
				ItemOperator *iOperator = new ItemOperator(starter);

				item = new ItemExpression(
					// this (OPERATOR),
					iOperator,
					// previous
					*(iter-1)					
				);

				// replace in the input
				iter = this->input.erase(iter-1, iter+1);
			}
			else if( starter->getArgs() == A_UNARY_LEFT )
			{
				ItemOperator *iOperator = new ItemOperator(starter);

				item = new ItemExpression(
					// this (OPERATOR),
					iOperator,
					// previous
					*(iter+1)
				);

				// replace in the input
				iter = this->input.erase(iter, iter+2);
			}

			this->input.insert(iter, item);
			
			// set as root
			this->root = item;

			return iter;
		}


		/**
		 * Builds a tree out of the stored sequence of items
         */
		void Parser::buildTree() {
			itemIterator i;
			size_t previousSize = 0;

			while( this->input.size() > 1 && previousSize != this->input.size() )
			{
				previousSize = this->input.size();

				for(i = this->input.begin(); i != this->input.end(); i++)
				{
					// shortcut (*i)-> to current->
					Item *current = *i;

					// get closest operator
					Item *next = getNextOfType(i, this->input.end(), T_OPERATOR);


					// is local peak?
					if( current->getType() == T_OPERATOR )
					{
						// peek at next - either end or of lower precedence
						if( next == NULL || next->getValue() < current->getValue() )
						{
							// replace it with expression
							i = addItem(current, i);

							break;
						}
					}
					else if( current->getType() == T_LITERAL )
					{
						// T_LITERAL in scan only valid when length of input = 1 (when it's the only input)
						if( this->input.begin()+1 == this->input.end() )
						{
							// make this value the only value, make it root
							this->input.clear();
							this->input.push_back(current);
							this->root = current;

							// and finish
							break;
						}
						/// @todo else ERROR
					}

				} // for
			} // while
		}


		/**
		 * Returns the root of tree
		 *
         * @return Item*
         */
		Item* Parser::getRoot() {
			if( this->root == NULL )
				this->buildTree();

			return this->root;
		}


		/**
		 * Fills the precedency table
		 * @return map<eOperator, int>
		 */
		map<eOperator, int> Parser::createPrecedencyTable() {

			map<eOperator, int> m;

			/**
			 * Fill the map
			 *
			 * higher value => greater precedency
			 */
			m[OP_PLUS]			= 0;
			m[OP_MINUS]			= 0;
			m[OP_UNARY_MINUS]	= 0;
			m[OP_DIVIDE]		= 1;
			m[OP_MULTIPLY]		= 1;
			m[OP_FACTORIAL]		= 2;
			m[OP_POWER]			= 3;
			m[OP_LOGARITHM]		= 4;

			return m;
		}
	
	}

}