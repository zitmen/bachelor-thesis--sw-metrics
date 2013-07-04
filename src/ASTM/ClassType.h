/*!
 * \file
 * ClassType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CLASS_TYPE_H_
#define _ASTM_CLASS_TYPE_H_

#include <vector>

#include "AggregateType.h"
#include "XmlDump.h"

class DerivesFrom;

/*!
 * \brief
 * Class types.
 *
 * \section cpp C++
 * - example:
 * \code
class A : public B	// this->derivesFrom = { "public B" }
{
	int i;	// this->members[0] = "int i"
	char c;	// this->members[1] = "char c"
};
\endcode
 *
 * \see AggregateType
 */
class ClassType : public AggregateType
{
	public:
		ClassType();
		virtual ~ClassType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Contains whether the class is derived from some other classes and specifies parameters of the derivation.
		 *
		 * \see DerivesFrom
		 */
		std::vector<DerivesFrom *> *derivesFrom;
};

#endif	// _ASTM_CLASS_TYPE_H_
