#include <string>
#include "Key.h"

Key::Key()
{
}

Key::Key(std::string &name, int id) : m_name(name), m_id(id)
{

}

Key::~Key()
{
}

std::string		&Key::getName(void)
{
	return(m_name);
}

int				Key::getId(void)
{
	return(m_id);
}

void			Key::setName(std::string &name)
{
	m_name = name;
}

void			Key::setId(int id)
{
	m_id = id;
}