/*!
 * \file
 * FunctionMemberAttributes.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_MEMBER_ATTRIBUTES_H_
#define _ASTM_FUNCTION_MEMBER_ATTRIBUTES_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

class VirtualSpecification;

/*!
 * \brief
 * Specifies various properties of function members.
 *
 * \section cpp C++
 * - example:
 * \code
class A
{
	public:
		friend ostream & operator<<(ostream &os);	// isFriend = true, isInline = false, isThisConst = false, virtualSpecifier = NonVirual
		
		inline void foo() const;	// isFriend = false, isInline = true, isThisConst = true, virtualSpecifier = NonVirual
		
		virtual void bar()	// isFriend = false, isInline = true, isThisConst = false, virtualSpecifier = Virual
		{
			...
		}
};
\endcode
 */
class FunctionMemberAttributes : public OtherSyntaxObject
{
	public:
		FunctionMemberAttributes();
		virtual ~FunctionMemberAttributes();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		bool isInline;
		bool isFriend;
		bool isThisConst;
		
		VirtualSpecification *virtualSpecifier;
};

#endif	// _ASTM_FUNCTION_MEMBER_ATTRIBUTES_H_
