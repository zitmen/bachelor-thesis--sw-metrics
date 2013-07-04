/*!
 * \file
 * BitFieldDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_FIELD_DEFINITION_H_
#define _ASTM_BIT_FIELD_DEFINITION_H_

#include <vector>

#include "DataDefinition.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Definitions of bit-field data.
 *
 * \section cpp C++
 * - example:
 * \code
struct Date
{
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)
   unsigned nMonthDay : 6;    // 0..31  (6 bits)
   unsigned nMonth    : 5;    // 0..12  (5 bits)
   unsigned nYear     : 8;    // 0..100 (8 bits)
};
\endcode
 * For nWeekDay: this->bitFieldSize = "3", this->identifierName = "nWeekDay", this->definitionType = "unsigned", ...
 *
 * \see DataDefinition
 */
class BitFieldDefinition : public DataDefinition
{
	public:
		BitFieldDefinition();
		virtual ~BitFieldDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Specifies size of member of bitfield.
		 *
		 * \see Expression
		 */
		Expression *bitFieldSize;
};

#endif	// _ASTM_BIT_FIELD_DEFINITION_H_
