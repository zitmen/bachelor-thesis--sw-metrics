/*!
 * \file
 * ReturnStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_RETURN_STATEMENT_H_
#define _ASTM_RETURN_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Statements that cause return from a function, possibly with a return value.
 *
 * \section example
 * - C++
 * \code
int main()
{
	return 0;	// this->returnValue = "0"
}
\endcode
 */
class ReturnStatement : public Statement
{
	public:
		ReturnStatement();
		virtual ~ReturnStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Return value.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *returnValue;
};

#endif	// _ASTM_RETURN_STATEMENT_H_
