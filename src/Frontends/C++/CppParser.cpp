#include "CppParser.h"
#include "cpp.tab.hpp"
#include "ActualParsingUnit.h"

#include <cstdio>

CppParser::CppParser()
{
	m_project = NULL;
	m_error = false;
}

CppParser::~CppParser()
{
	//if(m_project) delete m_project;
}

Project *
CppParser::parseFile(const std::string &filePath)
{
	m_project = new Project;
	CompilationUnit *unit = new CompilationUnit;
	unit->opensScope = new ProgramScope;
	unit->language = "C++";
	unit->srcFile = new SourceFile;
	unit->srcFile->pathName = filePath;
	//
	ActualParsingUnit::setUnit(unit);
	//
	m_project->files.push_back(unit);
	//
    m_error = (yyParseFile(unit->srcFile->pathName.c_str(), unit) != 0);
	//
	return m_project;
}

