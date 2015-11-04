#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);
	~Position();
	int			getX(void);
	int			getY(void);
	void		setX(int x);
	void		setY(int y);
private:
	int		m_x;
	int		m_y;
};