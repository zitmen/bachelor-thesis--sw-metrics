/*!
 * \file
 * Auto.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AUTO_H_
#define _ASTM_AUTO_H_

#include <vector>

#include "StorageSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Depicts storage for which the allocator is auto.
 *
 * \section cpp C++
 * auto int a;
 */
class Auto : public StorageSpecification
{
	public:
		Auto();
		virtual ~Auto();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_AUTO_H_
