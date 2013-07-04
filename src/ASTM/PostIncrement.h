/*!
 * \file
 * PostIncrement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_POST_INCREMENT_H_
#define _ASTM_POST_INCREMENT_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents post incrementation operator.
 *
 * \section cpp C++
 * - operator: ++
 * - example:
 * \code
x++
\endcode
 */
class PostIncrement : public UnaryOperator
{
	public:
		PostIncrement();
		virtual ~PostIncrement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_POST_INCREMENT_H_
