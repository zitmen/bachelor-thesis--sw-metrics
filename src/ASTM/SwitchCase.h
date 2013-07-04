/*!
 * \file
 * SwitchCase.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SWITCH_CASE_H_
#define _ASTM_SWITCH_CASE_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "Statement.h"

/*!
 * \brief
 * Parts of switch that are conditionaly executed.
 *
 * \section cpp C++
 * - example:
 * \code
switch(x)
{
	case 5:
		// this->statement
		break;
	
	default:
		// this->statement
		break;
}
\endcode
 */
class SwitchCase : public OtherSyntaxObject
{
	public:
		SwitchCase();
		virtual ~SwitchCase() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		Statement *statement;
};

#endif	// _ASTM_SWITCH_CASE_H_
