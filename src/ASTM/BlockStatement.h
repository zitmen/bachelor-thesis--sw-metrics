/*!
 * \file
 * BlockStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BLOCK_STATEMENT_H_
#define _ASTM_BLOCK_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class BlockScope;

/*!
 * \brief
 * Statements consisting of a series of substatements.
 *
 * \section example Example
 * - C++
 * \code
{	-> start of this->subStatements
	int a = 5;
	b += a;
}	-> end of this->subStatements
\endcode
 * this->opensScope = { "a" }
 */
class BlockStatement : public Statement
{
	public:
		BlockStatement();
		virtual ~BlockStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Body of block.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		std::vector<Statement *> *subStatements;
		
		/*!
		 * \brief
		 * List of variables declared inside of the block.
		 *
		 * \see \ref example
		 * \see BlockScope
		 */
		BlockScope *opensScope;
};

#endif	// _ASTM_BLOCK_STATEMENT_H_
