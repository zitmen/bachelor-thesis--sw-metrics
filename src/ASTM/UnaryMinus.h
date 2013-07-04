/*!
 * \file
 * UnaryMinus.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNARY_MINUS_H_
#define _ASTM_UNARY_MINUS_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents unary minus operator.
 *
 * \section cpp C++
 * - operator: -
 * - example:
 \code
-5
\endcode
 */
class UnaryMinus : public UnaryOperator
{
	public:
		UnaryMinus();
		virtual ~UnaryMinus();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_UNARY_MINUS_H_
