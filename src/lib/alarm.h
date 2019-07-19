#pragma once
#include <functional>
#include <string>
#include <vector>

class inputPin;
class outputPin;

class alarm;

typedef std::function<void(const alarm&,bool)> alarmCallback;

class alarmDefinition
{
public:
	alarmDefinition(const std::string name, const std::string description) {
		this->name = std::move(name);
		this->description = std::move(description);
	}
private:
	std::string name;
	std::string description;
};

class alarm
{
public:
	void SetStatus(bool active);
	bool IsAlarmInhibited() const;
private:
	alarmDefinition* definition;
	std::vector<alarmCallback> listeners;

	inputPin* inhibit;
	outputPin* active;
	
	std::string alarmData;
};
