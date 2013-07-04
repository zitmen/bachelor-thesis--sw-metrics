/*!
 * \file
 * FunctionType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_TYPE_H_
#define _ASTM_FUNCTION_TYPE_H_

#include <vector>

#include "Type.h"
#include "XmlDump.h"

class FormalParameterType;
class TypeReference;

/*!
 * \brief
 * Function types.
 *
 * \section cpp C++
 * - example:
 * \code
int foo(char *, int);	// this->returnType = "int", this->parameterTypes = { "char *", "int" }
\endcode
 */
class FunctionType : public Type
{
	public:
		FunctionType();
		virtual ~FunctionType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Types of function parameters.
		 *
		 * \see FormalParameterType
		 */
		std::vector<FormalParameterType *> parameterTypes;
		
		/*!
		 * \brief
		 * Return type.
		 *
		 * \see TypeReference
		 */
		TypeReference * returnType;
};

#endif	// _ASTM_FUNCTION_TYPE_H_
