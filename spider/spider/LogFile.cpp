#include "LogFile.h"

LogFile::LogFile(std::string &filename) : m_filename(filename), m_fs(filename.c_str(), std::fstream::out)
{
}

LogFile::~LogFile()
{
}

void		LogFile::logEvent(Event &toLog)
{
	if (m_fs)
	{
		m_fs << toLog.toString() << std::endl;
	}
}