#pragma once
class Modifier
{
public:
	Modifier();
	Modifier(Modifier &old);
	Modifier(bool Ctrl, bool Alt, bool AltGr, bool Shift);
	~Modifier();
	bool		getCtrl(void);
	bool		getAlt(void);
	bool		getAltGr(void);
	bool		getShift(void);
	void		setCtrl(bool Ctrl);
	void		setAlt(bool Alt);
	void		setAltGr(bool AltGr);
	void		setShift(bool Shift);
private:
	bool		m_Ctrl;
	bool		m_Alt;
	bool		m_AltGr;
	bool		m_Shift;
};

