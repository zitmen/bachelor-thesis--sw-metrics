/*!
 * \file
 * CaseBlock.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CASE_BLOCK_H_
#define _ASTM_CASE_BLOCK_H_

#include <vector>

#include "SwitchCase.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Switch cases that are executed when one of their values matches that of the enclosing switch statement.
 *
 * \section cpp C++
 * - example:
 * \code
switch(x)
{
	case 5:	// this->expression = "5"
		// SwitchCase::statement
		break;
}
\endcode
 */
class CaseBlock : public SwitchCase
{
	public:
		CaseBlock();
		virtual ~CaseBlock();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *expression;
};

#endif	// _ASTM_CASE_BLOCK_H_
