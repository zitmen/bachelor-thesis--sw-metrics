/*!
 * \file
 * Name.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAME_H_
#define _ASTM_NAME_H_

#include <string>
#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

/*!
 * \brief
 * Names that may appear in declarations and definitions.
 */
class Name : public OtherSyntaxObject
{
	public:
		Name();
		Name(const std::string &name);
		virtual ~Name();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		std::string nameString;
};

#endif	// _ASTM_NAME_H_
