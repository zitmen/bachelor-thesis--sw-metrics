/*!
 * \file
 * CatchBlock.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CATCH_BLOCK_H_
#define _ASTM_CATCH_BLOCK_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

class DataDefinition;
class Statement;
class Type;

/*!
 * \brief
 * Parts of try statement that specify a statement to execute under specified exception conditions.
 *
 * \section cpp C++
 * - example:
 * \code
catch(Exception e)	// exceptionVariable = "Exception e"
{
	// body
}
\endcode
 * 
 */
class CatchBlock : public OtherSyntaxObject
{
	public:
		CatchBlock();
		virtual ~CatchBlock();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		std::vector<Type *> exceptions;
		Statement *body;
};

#endif	// _ASTM_CATCH_BLOCK_H_
