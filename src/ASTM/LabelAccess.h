/*!
 * \file
 * LabelAccess.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LABEL_ACCESS_H_
#define _ASTM_LABEL_ACCESS_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class Name;
class LabelDefinition;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class LabelAccess : public Expression
{
	public:
		LabelAccess();
		virtual ~LabelAccess();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Name *aName;
		LabelDefinition *aDefinition;
};

#endif	// _ASTM_LABEL_ACCESS_H_
