/*!
 * \file
 * BinaryOperator.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BINARY_OPERATOR_H_
#define _ASTM_BINARY_OPERATOR_H_

#include <vector>

#include "OtherSyntaxObject.h"

/*!
 * \brief
 * Operators taking two operands.
 */
class BinaryOperator : public OtherSyntaxObject
{
	public:
		BinaryOperator();
		virtual ~BinaryOperator() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_BINARY_OPERATOR_H_
