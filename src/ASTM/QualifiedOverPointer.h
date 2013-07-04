/*!
 * \file
 * QualifiedOverPointer.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_QUALIFIED_OVER_POINTER_H_
#define _ASTM_QUALIFIED_OVER_POINTER_H_

#include <vector>

#include "QualifiedIdentifierReference.h"
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
class QualifiedOverPointer : public QualifiedIdentifierReference
{
	public:
		QualifiedOverPointer();
		virtual ~QualifiedOverPointer();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_QUALIFIED_OVER_POINTER_H_
