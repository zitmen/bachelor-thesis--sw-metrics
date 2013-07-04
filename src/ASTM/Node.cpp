#include "Node.h"
#include "GASTMObject.h"

#include <algorithm>

void
Node::identify()
{
	m_id.clear();
	//
	if(m_node)
		m_node->identify(m_id);
}

Node::Node(GASTMObject *node)
{
	m_node = node;
	identify();
}

Node::~Node()
{
	//
}

void
Node::setNode(GASTMObject *node)
{
	m_node = node;
	identify();
}

int
Node::operator[](size_t index) const
{
	return m_id[index];
}

bool
Node::operator==(int id) const
{
	return (std::find(m_id.begin(), m_id.end(), id) != m_id.end());
}

bool
Node::operator!=(int id) const
{
	return !((*this) == id);
}

bool
Node::operator==(const Node &node) const
{
	return (node == m_id[0]);
}

bool
Node::operator!=(const Node &node) const
{
	return (node != m_id[0]);
}
