/*!
 * \file
 * SourceFile.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SOURCE_FILE_H_
#define _ASTM_SOURCE_FILE_H_

#include <vector>
#include <string>

#include "GASTMSourceObject.h"
#include "XmlDump.h"

class SourceLocation;

/*!
 * \brief
 * Represents the source file.
 */
class SourceFile : public GASTMSourceObject
{
	public:
		SourceFile();
		virtual ~SourceFile();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Path to source file.
		 */
		std::string pathName;
		
		/*!
		 * \brief
		 * Pointer to the first token in the file.
		 */
		SourceLocation *firstToken;
		
		/*!
		 * \brief
		 * Pointer to the last token in the file.
		 */
		SourceLocation *lastToken;
};

#endif	// _ASTM_SOURCE_FILE_H_
