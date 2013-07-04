/*!
 * \file
 * ForStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FOR_STATEMENT_H_
#define _ASTM_FOR_STATEMENT_H_

#include <vector>

#include "LoopStatement.h"
#include "XmlDump.h"

class Expression;
class Statement;

/*!
 * \brief
 * Loop statement with initializing and incrementing parts.
 *
 * \section example Example
 * - C++
 * \code
for(int i = 0; i < 10; i++)	// this->initBody = "int i = 0", this->condition = "i < 10", this->iterationBody = "i++"
{
	// this->body
}
\endcode
 *
 * \see LoopStatement
 */
class ForStatement : public LoopStatement
{
	public:
		ForStatement();
		virtual ~ForStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Initializing part.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *initBody;
		
		/*!
		 * \brief
		 * Incrementing part.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *iterationBody;
};

#endif	// _ASTM_FOR_STATEMENT_H_
