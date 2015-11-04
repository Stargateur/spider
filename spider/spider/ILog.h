#pragma once
#include "Event.h"

class ILog
{
public:
	ILog();
	~ILog();
	virtual void logEvent(Event &toLog) = 0;
};