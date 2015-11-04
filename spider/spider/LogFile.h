#pragma once
#include "ILog.h"
#include <string>
#include <fstream>

class LogFile : public ILog
{
public:
	LogFile(std::string &filename);
	~LogFile();
	virtual void logEvent(Event &toLog);
private:
	std::string		m_filename;
	std::fstream	m_fs;
};

