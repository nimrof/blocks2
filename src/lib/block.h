#pragma once
#include <vector>

#include "alarm.h"
#include "message.h"
#include "pin.h"

class blockDefinition
{
public:
protected:
	std::string type;
	std::vector<pinDefinition> inputs;
	std::vector<pinDefinition> output;
	std::vector<pinDefinition> configuration;
	std::vector<alarmDefinition> alarms;
};

class block
{
public:
	virtual void run() = 0;
	virtual void ProcessMsg(const message& msg) {};
	virtual block* Create(const std::vector<pin>& configuration) = 0;
	virtual std::string GetType() = 0;
	virtual version GetVersion() { return { 0,0 }; }
	virtual bool IsInputTypesSupported(const std::vector<dataType>& inputTypes);
protected:
	void SetAlarmStatus(alarm& alarm, bool active);

	blockDefinition* definition = nullptr;
	std::string name;
	std::string typeName;

	std::vector<alarm> alarms;
	std::vector<inputPin> inputs;
	std::vector<outputPin> output;
	std::vector<inputPin> alarmInhibit;
	std::vector<outputPin> alarmActive;
};
