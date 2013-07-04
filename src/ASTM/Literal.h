/*!
 * \file
 * Literal.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LITERAL_H_
#define _ASTM_LITERAL_H_

#include <string>
#include <vector>

#include "Expression.h"

/*!
 * \brief
 * Literal expressions.
 *
 * Literal::value contains token, fe. "string", 1.75, etc.
 * Subclasses are used primarly for resolution of literal types.
 */
class Literal : public Expression
{
	public:
		Literal();
		virtual ~Literal() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		std::string value;
};

#endif	// _ASTM_LITERAL_H_
