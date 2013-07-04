/*!
 * \file
 * DefaultBlock.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DEFAULT_BLOCK_H_
#define _ASTM_DEFAULT_BLOCK_H_

#include <vector>

#include "SwitchCase.h"
#include "XmlDump.h"

/*!
 * \brief
 * Switch cases that are executed when no other switch case in the enclosing switch is executed.
 *
 * \section cpp C++
 * - example:
 * \code
switch(x)
{
	default:
		// SwitchCase::statement
		break;
}
\endcode
 */
class DefaultBlock : public SwitchCase
{
	public:
		DefaultBlock();
		virtual ~DefaultBlock();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DEFAULT_BLOCK_H_
