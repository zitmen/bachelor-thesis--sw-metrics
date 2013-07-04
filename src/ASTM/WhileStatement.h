/*!
 * \file
 * WhileStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_WHILE_STATEMENT_H_
#define _ASTM_WHILE_STATEMENT_H_

#include <vector>

#include "LoopStatement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Loop statement whose body is repeatedly executed while a specified condition, tested before each execution, is true.
 *
 * \section cpp C++
 * - example:
 * \code
while(x < 10)	// this->condition = "x < 10"
{
	// this->body
}
\endcode
 *
 * \see LoopStatement
 */
class WhileStatement : public LoopStatement
{
	public:
		WhileStatement();
		virtual ~WhileStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_WHILE_STATEMENT_H_
