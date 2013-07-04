/*!
 * \file
 * Static.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STATIC_H_
#define _ASTM_STATIC_H_

#include <vector>

#include "StorageSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Depicts storage that is static.
 *
 * \section cpp C++
 * Any function declared in file scope or class scope or any variable declared in class scope or as function persistent variable.
 */
class Static : public StorageSpecification
{
	public:
		Static();
		virtual ~Static();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_STATIC_H_
