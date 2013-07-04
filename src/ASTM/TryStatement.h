/*!
 * \file
 * TryStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_TRY_STATEMENT_H_
#define _ASTM_TRY_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class CatchBlock;

/*!
 * \brief
 * Exception-handling statements, consisting of a substatement that may throw exceptions and catch blocks to handle them.
 *
 * \section example Example
 * - C++ has no finally block, so it remains empty (NULL)
 * \code
try	
{
	// this->guardedStatement
}
catch(int code)			// this->catchBlocks[0]
{
	...
}
catch(const char *msg)	// this->catchBlocks[1]
{
	...
}
// this->finalStatement = NULL;
\endcode
 *
 * - Java
 * \code
try	 {
	// this->guardedStatement
} catch(int code) {			// this->catchBlocks[0]
	...
} catch(const char *msg) {	// this->catchBlocks[1]
	...
} finally {
	// this->finalStatement
}
\endcode
 */
class TryStatement : public Statement
{
	public:
		TryStatement();
		virtual ~TryStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Catch blocks for exception handling.
		 *
		 * \see \ref example
		 * \see CatchBlock
		 */
		std::vector<CatchBlock *> catchBlocks;
		
		/*!
		 * \brief
		 * Finally statement that usually serves as cleaner.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *finalStatement;
		
		/*!
		 * \brief
		 * Statement that is surrounded by Try block.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		Statement *guardedStatement;
};

#endif	// _ASTM_TRY_STATEMENT_H_
