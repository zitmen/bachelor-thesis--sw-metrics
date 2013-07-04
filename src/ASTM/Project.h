/*!
 * \file
 * Project.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PROJECT_H_
#define _ASTM_PROJECT_H_

#include <vector>

#include "GASTMSemanticObject.h"
#include "XmlDump.h"

class CompilationUnit;
class GlobalScope;

/*!
 * \brief
 * The collection of compilation units to be modelled/analyzed as a whole.
 */
class Project : public GASTMSemanticObject
{
	public:
		Project();
		virtual ~Project();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Files that are associated to project.
		 */
		std::vector<CompilationUnit *> files;
		
		/*!
		 * \brief
		 * Scope surrounding the whole project.
		 */
		GlobalScope *outerScope;
};

#endif	// _ASTM_PROJECT_H_
