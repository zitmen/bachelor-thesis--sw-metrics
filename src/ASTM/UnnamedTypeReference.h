/*!
 * \file
 * UnnamedTypeReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNNAMED_TYPE_REFERENCE_H_
#define _ASTM_UNNAMED_TYPE_REFERENCE_H_

#include <vector>

#include "TypeReference.h"
#include "XmlDump.h"

class Type;

/*!
 * \brief
 * References to types without use of a name for the referenced type.
 *
 * \section cpp C++
 * - example:
 * \code
unsigned int	// this->type = "unsigned int"
\endcode
 */
class UnnamedTypeReference : public TypeReference
{
	public:
		UnnamedTypeReference();
		virtual ~UnnamedTypeReference();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Type that is referenced.
		 *
		 * \see Type
		 */
		Type *type;
};

#endif	// _ASTM_UNNAMED_TYPE_REFERENCE_H_
