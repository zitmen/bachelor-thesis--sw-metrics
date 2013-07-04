/*!
 * \file
 * LabelDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LABEL_DEFINITION_H_
#define _ASTM_LABEL_DEFINITION_H_

#include <vector>

#include "DefinitionUnit.h"
#include "XmlDump.h"

class Name;
class LabelType;

/*!
 * \brief
 * Definitions of labels.
 *
 * \section cpp C++
 * - example:
 * \code
...
clean: delete var;	// this->labelName = "clean", this->labelType = new LabelType()
...
\endcode
 */
class LabelDefinition : public DefinitionUnit
{
	public:
		LabelDefinition();
		virtual ~LabelDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Type of label. Only for semantics. Determines that type of this construct is label.
		 *
		 * \see LabelType
		 */
		LabelType *labelType;
		
		/*!
		 * \brief
		 * Label name.
		 *
		 * \see Name
		 */
		Name *labelName;
};

#endif	// _ASTM_LABEL_DEFINITION_H_
