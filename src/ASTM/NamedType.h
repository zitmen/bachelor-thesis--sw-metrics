/*!
 * \file
 * NamedType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAMED_TYPE_H_
#define _ASTM_NAMED_TYPE_H_

#include <vector>

#include "DataType.h"
#include "XmlDump.h"

class Type;

/*!
 * \brief
 * Uses of named types.
 *
 * \section cpp C++
 * - example:
 * \code
typedef BYTE unsigned char;	// this->body = "unsigned char"
\endcode
 */
class NamedType : public DataType
{
	public:
		NamedType();
		virtual ~NamedType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Body of type.
		 *
		 * \see Type
		 */
		Type *body;
};

#endif	// _ASTM_NAMED_TYPE_H_
