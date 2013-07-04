/*!
 * \file
 * Assign.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ASSIGN_H_
#define _ASTM_ASSIGN_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents assignment operator.
 *
 * \section cpp C++
 * - operator: =
 * - example:
 * \code
x = 5
\endcode
 */
class Assign : public BinaryOperator
{
	public:
		Assign();
		virtual ~Assign();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_ASSIGN_H_
