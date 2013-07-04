/*!
 * \file
 * GASTMSyntaxObject.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _GASTM_SYNTAX_OBJECT_H_
#define _GASTM_SYNTAX_OBJECT_H_

#include <vector>

#include "GASTMObject.h"
#include "SourceLocation.h"

/*!
 * \brief
 * All syntax constructs.
 */
class GASTMSyntaxObject : public GASTMObject
{
	public:
		GASTMSyntaxObject();
		virtual ~GASTMSyntaxObject() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * All syntactic constructs have infmormation about positions of their tokens,
		 * so the analysis is connected up to source code level.
		 * This is the first token of some syntax object.
		 */
		SourceLocation *locFirst;
		
		/*!
		 * \brief
		 * All syntactic constructs have infmormation about positions of their tokens,
		 * so the analysis is connected up to source code level.
		 * This is the last token of some syntax object.
		 */
		SourceLocation *locLast;
};

#endif	// _GASTM_SYNTAX_OBJECT_H_
