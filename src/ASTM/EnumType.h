/*!
 * \file
 * EnumType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ENUM_TYPE_H_
#define _ASTM_ENUM_TYPE_H_

#include <vector>

#include "DataType.h"
#include "XmlDump.h"

class EnumLiteralDefinition;

/*!
 * \brief
 * Enumerated types.
 *
 * \section cpp C++
 * - example:
 * \code
enum
{
	SUNDAY,		// -> this->enumLiterals[0]
	MONDAY,		// -> this->enumLiterals[1]
	TUESDAY,	// -> this->enumLiterals[2]
	WEDNESDAY,	// -> this->enumLiterals[3]
	THURSDAY,	// -> this->enumLiterals[4]
	FRIDAY,		// -> this->enumLiterals[5]
	SATURDAY	// -> this->enumLiterals[6]
};
\endcode
 */
class EnumType : public DataType
{
	public:
		EnumType();
		virtual ~EnumType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Constants defined in enumeration.
		 *
		 * \see EnumLiteralDefinition
		 */
		std::vector<EnumLiteralDefinition *> enumLiterals;
};

#endif	// _ASTM_ENUM_TYPE_H_
