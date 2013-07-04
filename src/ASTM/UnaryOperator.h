/*!
 * \file
 * .h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNARY_OPERATOR_H_
#define _ASTM_UNARY_OPERATOR_H_

#include <vector>

#include "OtherSyntaxObject.h"

/*!
 * \brief
 * Operators taking a single operand.
 */
class UnaryOperator : public OtherSyntaxObject
{
	public:
		UnaryOperator();
		virtual ~UnaryOperator() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_UNARY_OPERATOR_H_
