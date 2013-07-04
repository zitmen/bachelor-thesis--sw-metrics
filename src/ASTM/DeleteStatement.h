/*!
 * \file
 * DeleteStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DELETE_STATEMENT_H_
#define _ASTM_DELETE_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Statements that deallocate storage.
 *
 * \section example Example
 * - C++
 * \code
delete obj;		// this->operand = "obj", this->deleteArray = false
delete [] arr;	// this->operand = "arr", this->deleteArray = true
\endcode
 */
class DeleteStatement : public Statement
{
	public:
		DeleteStatement();
		virtual ~DeleteStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Object that will be deleted.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *operand;
		
		/*!
		 * \brief
		 * Specifies that object is an array or not.
		 *
		 * \see \ref example
		 */
		bool deleteArray;
};

#endif	// _ASTM_DELETE_STATEMENT_H_
