/*!
 * \file
 * DoWhileStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DO_WHILE_STATEMENT_H_
#define _ASTM_DO_WHILE_STATEMENT_H_

#include <vector>

#include "LoopStatement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Loop statement whose body is repeatedly executed while a specified condition, tested after each execution, is true.
 *
 * \section example Example
 * - C++
 * \code
do
{
	// this->body
} while(x < 10);	// this->condition = "x < 10"
\endcode
 *
 * \see LoopStatement
 */
class DoWhileStatement : public LoopStatement
{
	public:
		DoWhileStatement();
		virtual ~DoWhileStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DO_WHILE_STATEMENT_H_
