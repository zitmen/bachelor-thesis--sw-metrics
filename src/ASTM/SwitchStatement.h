/*!
 * \file
 * SwitchStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SWITCH_STATEMENT_H_
#define _ASTM_SWITCH_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;
class BlockScope;

/*!
 * \brief
 * Statements that conditionally execute one of many substatements.
 *
 * \section example Example
 * - C++
 * \code
switch(x)	// this->switchExpression = "x"
{
	case 3:
	case 4:
		break;
	
	case 5:
		break;
	
	default:
		break;
}
\endcode
 */
class SwitchStatement : public Statement
{
	public:
		SwitchStatement();
		virtual ~SwitchStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Possible cases of expression.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *body;
		
		/*!
		 * \brief
		 * Expression that determines which of cases will be executed.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *switchExpression;
		
		/*!
		 * \brief
		 * List of variables declared inside of the SWITCH statement.
		 *
		 * \see BlockScope
		 */
		BlockScope *opensScope;
};

#endif	// _ASTM_SWITCH_STATEMENT_H_
