#pragma once
#include <string>
class Button
{
public:
	Button();
	Button(std::string &name, int id);
	~Button();
	std::string	getName(void);
	int			getId(void);
	void		setName(std::string &name);
	void		setId(int id);
private:
	std::string	m_name;
	int			m_id;
};

