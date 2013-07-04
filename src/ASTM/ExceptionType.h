/*!
 * \file
 * ExceptionType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EXCEPTION_TYPE_H_
#define _ASTM_EXCEPTION_TYPE_H_

#include <vector>

#include "DataType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Types used in the context of exception heneration/handling.
 * For example built-in exceptions in Python, etc.
 */
class ExceptionType : public DataType
{
	public:
		ExceptionType();
		virtual ~ExceptionType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_EXCEPTION_TYPE_H_
