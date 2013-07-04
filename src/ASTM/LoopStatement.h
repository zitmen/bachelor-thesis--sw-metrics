/*!
 * \file
 * LoopStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LOOP_STATEMENT_H_
#define _ASTM_LOOP_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;
class BlockScope;

/*!
 * \brief
 * Statements with a substatements (body) that is potentially repeatedly executed.
 *
 * \see WhileStatement
 * \see ForStatement
 */
class LoopStatement : public Statement
{
	public:
		LoopStatement();
		virtual ~LoopStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Condition that decides whether the body will be executed or not.
		 *
		 * \see Expression
		 */
		Expression *condition;
		
		/*!
		 * \brief
		 * Body of loop that is repeatedly executed.
		 *
		 * \see Statement
		 */
		Statement *body;
		
		/*!
		 * \brief
		 * List of variables declared inside of the loop.
		 *
		 * \see BlockScope
		 */
		BlockScope *opensScope;
};

#endif	// _ASTM_LOOP_STATEMENT_H_
