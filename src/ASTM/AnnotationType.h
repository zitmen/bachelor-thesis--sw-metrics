/*!
 * \file
 * AnnotationType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ANNOTATION_TYPE_H_
#define _ASTM_ANNOTATION_TYPE_H_

#include <vector>

#include "AggregateType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Denotations that complete or extend the definitions of other types.
 *
 * \section java Java
 * - example:
 * \code

public @interface MyAnnotation {	// this = "@interface"
	...
}

@MyAnnotation public void mymethod() {	// this = "@MyAnnotation"
   ....
}
\endcode
 *
 * \see AggregateType
 */
class AnnotationType : public AggregateType
{
	public:
		AnnotationType();
		virtual ~AnnotationType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_ANNOTATION_TYPE_H_
