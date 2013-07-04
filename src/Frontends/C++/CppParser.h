#ifndef _CPP_PARSER_ISO2003_H_
#define _CPP_PARSER_ISO2003_H_

#include "../../ASTM/ASTM.h"

#include <string>

class CppParser
{
	private:
		Project *m_project;
		bool m_error;

	public:
		CppParser();
		~CppParser();

		Project * parseFile(const std::string &filePath);

		inline bool errorOccured() const { return m_error; }
		inline Project * getProject() const { return m_project; }
};

#endif	// _CPP_PARSER_ISO2003_H_

