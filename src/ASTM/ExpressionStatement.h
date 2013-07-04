/*!
 * \file
 * ExpressionStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EXPRESSION_STATEMENT_H_
#define _ASTM_EXPRESSION_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Statements comprised of just an expression
 *
 * \section example
 * - C++
 * \code
a += 5;	// this->expression = "a += 5"
\endcode
 */
class ExpressionStatement : public Statement
{
	public:
		ExpressionStatement();
		virtual ~ExpressionStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Executed expression.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *expression;
};

#endif	// _ASTM_EXPRESSION_STATEMENT_H_
