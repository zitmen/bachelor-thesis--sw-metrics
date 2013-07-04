/*!
 * \file
 * Comment.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_COMMENT_H_
#define _ASTM_COMMENT_H_

#include <string>
#include <vector>

#include "PreprocessorElement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Comments appearing in source files.
 *
 * \section cpp C++
 * - example:
 * \code
// This is a comment.
\endcode
 * 
 * this->text = " This is a comment."
 * this->locationInfo->token = "// This is a comment."
 */
class Comment : public PreprocessorElement
{
	public:
		Comment();
		virtual ~Comment();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Text of comment.
		 */
		std::string text;
};

#endif	// _ASTM_COMMENT_H_
