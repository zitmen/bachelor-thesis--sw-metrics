/*!
 * \file
 * ThrowStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_THROW_STATEMENT_H_
#define _ASTM_THROW_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Statements that cause an exception to be thrown.
 * 
 * \section example Example
 * - C++
 * \code
...
Exception *e = new Exception("division by zero");
throw(e);	// this->exception = "e"
...
\endcode
 */
class ThrowStatement : public Statement
{
	public:
		ThrowStatement();
		virtual ~ThrowStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Raised exception (usually information about error).
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *exception;
};

#endif	// _ASTM_THROW_STATEMENT_H_
