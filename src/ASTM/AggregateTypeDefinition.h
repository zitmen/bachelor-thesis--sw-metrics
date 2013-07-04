/*!
 * \file
 * AggregateTypeDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AGGREGATE_TYPE_DEFINITION_H_
#define _ASTM_AGGREGATE_TYPE_DEFINITION_H_

#include <vector>

#include "TypeDefinition.h"
#include "XmlDump.h"

class AggregateType;

/*!
 * \brief
 * Definitions of aggregate types.
 *
 * \section cpp C++
 * - example:
 * \code
struct Time			// this->name = "Time"
{	// -> start of this->aggregateType
	int hours;
	int minutes;
	int seconds;
};	// -> end of this->aggregateType
\endcode
 *
 * \see TypeDefinition
 */
class AggregateTypeDefinition : public TypeDefinition
{
	public:
		AggregateTypeDefinition();
		virtual ~AggregateTypeDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Aggregate type that is defined.
		 *
		 * \see AggregateType
		 */
		AggregateType *aggregateType;
};

#endif	// _ASTM_AGGREGATE_TYPE_DEFINITION_H_
