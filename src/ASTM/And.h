/*!
 * \file
 * And.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AND_H_
#define _ASTM_AND_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents logical AND operator.
 *
 * \section cpp C++
 * - operator: &&
 * - example:
 * \code
x && y
\endcode
 */
class And : public BinaryOperator
{
	public:
		And();
		virtual ~And();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_AND_H_
