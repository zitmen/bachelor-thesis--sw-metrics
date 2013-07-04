/*!
 * \file
 * JumpStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_JUMP_STATEMENT_H_
#define _ASTM_JUMP_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Statements that branch to a label.
 *
 * \section example
 * - C++
 * \code
goto nav;	// this->target = "nav"
\endcode
 */
class JumpStatement : public Statement
{
	public:
		JumpStatement();
		virtual ~JumpStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Target where statement jumps.
		 *
		 * \see \ref example
		 * \see Expression
		 */
		Expression *target;
};

#endif	// _ASTM_JUMP_STATEMENT_H_
