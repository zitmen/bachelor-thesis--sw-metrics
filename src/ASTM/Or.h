/*!
 * \file
 * Or.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_OR_H_
#define _ASTM_OR_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents logical OR operator.
 *
 * \section cpp C++
 * - operator: ||
 * - example:
 * \code
x || y
\endcode
 */
class Or : public BinaryOperator
{
	public:
		Or();
		virtual ~Or();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_OR_H_
