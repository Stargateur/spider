#pragma once
#include <string>

class Key
{
public:
	Key();
	Key(std::string &name, int id);
	~Key();
	std::string &getName(void);
	int			getId(void);
	void		setName(std::string &name);
	void		setId(int id);
private:
	std::string		m_name;
	int				m_id;
};

