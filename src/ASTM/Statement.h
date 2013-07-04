/*!
 * \file
 * Statement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STATEMENT_H_
#define _ASTM_STATEMENT_H_

#include <vector>

#include "GASTMSyntaxObject.h"

/*!
 * \brief
 * All statements.
 */
class Statement : public GASTMSyntaxObject
{
	public:
		Statement();
		virtual ~Statement() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_STATEMENT_H_
