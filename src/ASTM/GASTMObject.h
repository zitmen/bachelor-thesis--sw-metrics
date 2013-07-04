/*!
 * \file
 * GASTMObject.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _GASTM_OBJECT_H_
#define _GASTM_OBJECT_H_

#include <vector>

#include "XmlDump.h"

/*!
 * \brief
 * The root of the GASTM class hierarchy.
 */
class GASTMObject
{
	public:
		GASTMObject();
		virtual ~GASTMObject() = 0;
		
		/*!
		 * \brief
		 * Link to parent node used for backward traversing tree.
		 */
		GASTMObject *parent;
		
		/*!
		 * \brief
		 * Completely identifies node (including class inharitance hierarchy).
		 *
		 * \param id
		 * [out] Vector which will save identification of node. Values are integer constants selected from NodeId enumeration.
		 *
		 * For example node IntegerLiteral is identified as { INTEGER_LITERAL, LITERAL, EXPRESSION, GASTM_SYNTAX_OBJECT, GASTM_OBJECT }.
		 *
		 * \see
		 * NodeId
		 */
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Makes Xml dump of a class. Saves all member variables as TiXmlElement.
		 *
		 * \param parent
		 * [out] Element that is parent to the element that represents this class.
		 *
		 * For example:
		 * \code
...
<class name = "CompoundStatement">
	<member name="subStatements" index="0">
		<class name = "IfStatement">
			<member name="condition">
				<class name = "Expression">
					...
				</class>
			</member>
			<member name="onTrueBody">
				<class name = "CoumpoundStatement">
					...
				</class>
			</member>
			<member name="onFalseBody">
				<class name = "CoumpoundStatement">
					...
				</class>
			</member>
			<member name="locationInfo">NULL</member>
		</class>
	</member>
</class>
...
		 *
		 */
		virtual void dumpXml(TiXmlElement *parent) const = 0;
};

#endif	// _GASTM_OBJECT_H_
