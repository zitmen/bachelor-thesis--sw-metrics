/*!
 * \file
 * OperatorAssign.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_OPERATOR_ASSIGN_H_
#define _ASTM_OPERATOR_ASSIGN_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Assignment operators compounded with a binary operator.
 *
 * \section cpp C++
 * - operators: +=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=
 */
class OperatorAssign : public BinaryOperator
{
	public:
		OperatorAssign();
		virtual ~OperatorAssign();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		BinaryOperator *op;
};

#endif	// _ASTM_OPERATOR_ASSIGN_H_
