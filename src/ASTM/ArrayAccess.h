/*!
 * \file
 * ArrayAccess.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ARRAY_ACCESS_H_
#define _ASTM_ARRAY_ACCESS_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class ArrayAccess : public Expression
{
	public:
		ArrayAccess();
		virtual ~ArrayAccess();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *arrayName;
		std::vector<Expression *> subScripts;
};

#endif	// _ASTM_ARRAY_ACCESS_H_
