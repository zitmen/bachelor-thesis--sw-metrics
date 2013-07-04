/*!
 * \file
 * UnaryPlus.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNARY_PLUS_H_
#define _ASTM_UNARY_PLUS_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents unary plus operator.
 *
 * \section cpp C++
 * - operator: +
 * - example:
 * \code
+5
\endcode
 */
class UnaryPlus : public UnaryOperator
{
	public:
		UnaryPlus();
		virtual ~UnaryPlus();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_UNARY_PLUS_H_
