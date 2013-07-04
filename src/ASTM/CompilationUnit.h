/*!
 * \file
 * CompilationUnit.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_COMPILATION_UNIT_H_
#define _ASTM_COMPILATION_UNIT_H_

#include <string>
#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

class ProgramScope;
class DefinitionUnit;
class SourceFile;

/*!
 * \brief
 * Unit of compilation; typically coresponding to a source file.
 */
class CompilationUnit : public OtherSyntaxObject
{
	public:
		CompilationUnit();
		virtual ~CompilationUnit();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Programming language of source code.
		 */
		std::string language;
		
		/*!
		 * \brief
		 * Information about the source code (file path and tokens).
		 */
		SourceFile *srcFile;
		
		/*!
		 * \brief
		 * Optional semantic variable. Can contain some scope information, f.e. Java/Python package.
		 */
		ProgramScope *opensScope;
		
		/*!
		 * \brief
		 * Contains the whole parsed source code fragmented into DefinitionUnits (classes, functions, etc.).
		 */
		std::vector<DefinitionUnit *> *fragments;
};

#endif	// _ASTM_COMPILATION_UNIT_H_
