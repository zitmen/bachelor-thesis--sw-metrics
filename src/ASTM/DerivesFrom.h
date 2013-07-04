/*!
 * \file
 * DerivesFrom.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DERIVES_FROM_H_
#define _ASTM_DERIVES_FROM_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

class AccessKind;
class NamedType;

/*!
 * \brief
 * Specifies relationship between class types and the types from which they are derived.
 *
 * \section cpp C++
 * - example:
 * \code
class A	// this = NULL
{ .. };

class AB : virtual public A	// this->isVirtual = true, accessKind = "public", className = "A"
{ .. };

class AC : virtual public A	// this->isVirtual = true, accessKind = "public", className = "A"
{ .. };

class ABC : public AB, public AC	// { this->isVirtual = false, accessKind = "public", className = "AB" },
{ .. };                         	// { this->isVirtual = false, accessKind = "public", className = "AC" }
\endcode
 */
class DerivesFrom : public OtherSyntaxObject
{
	public:
		DerivesFrom();
		virtual ~DerivesFrom();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		bool isVirtual;
		
		AccessKind *accessKind;
		NamedType *className;
};

#endif	// _ASTM_DERIVES_FROM_H_
