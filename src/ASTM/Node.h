#ifndef _ASTM_NODE_H_
#define _ASTM_NODE_H_

#include <vector>

class GASTMObject;

class Node
{
	private:
		GASTMObject *m_node;
		std::vector<int> m_id;
		//
		void identify();
		
	public:
		Node(GASTMObject *node = NULL);
		virtual ~Node();
		//
		void setNode(GASTMObject *node);
		int  operator[](size_t index) const;
		bool operator==(int id) const;
		bool operator!=(int id) const;
		bool operator==(const Node &node) const;
		bool operator!=(const Node &node) const;
};

#endif	// _ASTM_NODE_H_
