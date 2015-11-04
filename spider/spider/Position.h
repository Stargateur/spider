#pragma once
class Position
{
public:
	Position();
	Position(int x, int y, int z);
	~Position();
	int			getX(void);
	int			getY(void);
	int			getZ(void);
	void		setX(int x);
	void		setY(int y);
	void		setZ(int z);
private:
	int		m_x;
	int		m_y;
	int		m_z;
};