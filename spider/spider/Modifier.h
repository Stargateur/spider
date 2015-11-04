#pragma once
class Modifier
{
public:
	Modifier();
	Modifier(Modifier const &old);
	Modifier(bool Ctrl, bool Alt, bool CapsLock, bool Shift);
	~Modifier();
	bool		getCtrl(void);
	bool		getAlt(void);
	bool		getShift(void);
	bool		getCapsLock(void);
	void		setCtrl(bool Ctrl);
	void		setAlt(bool Alt);
	void		setShift(bool Shift);
	void		setCapsLock(bool CapsLock);
private:
	bool		m_Ctrl;
	bool		m_Alt;
	bool		m_Shift;
	bool		m_CapsLock;
};

