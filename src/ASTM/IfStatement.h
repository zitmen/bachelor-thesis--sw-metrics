/*!
 * \file
 * IfStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_IF_STATEMENT_H_
#define _ASTM_IF_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;
class BlockScope;

/*!
 * \brief
 * Statements that conditionally execute one of two elements.
 *
 * \section example Example
 * - C++
 * \code
if(x == 5)	// this->condition = "x == 5"
{
	// this->thenBody
}
else
{
	// this->elseBody
}
\endcode
 */
class IfStatement : public Statement
{
	public:
		IfStatement();
		virtual ~IfStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Condition.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *condition;
		
		/*!
		 * \brief
		 * Statement that is be executed if the condition is true.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *thenBody;
		
		/*!
		 * \brief
		 * Statement that is be executed if the condition is false.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *elseBody;
		
		/*!
		 * \brief
		 * List of variables declared inside of the IF statement.
		 *
		 * \see BlockScope
		 */
		BlockScope *opensScope;
};

#endif	// _ASTM_IF_STATEMENT_H_
