/*!
 * \file
 * External.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EXTERNAL_H_
#define _ASTM_EXTERNAL_H_

#include <vector>

#include "StorageSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Depicts storage that is external.
 *
 * \section cpp C++
 * - keyword: extern
 */
class External : public StorageSpecification
{
	public:
		External();
		virtual ~External();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_EXTERNAL_H_
