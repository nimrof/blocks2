#pragma once
#include <string>
#include <vector>

#include "types.h"

class signal;
class inputPin;

class pinDefinition
{
public:
	pinDefinition() = default;
	pinDefinition(const std::string& name, dataType acceptedTypes)
	{
		this->name = std::move(name);
		this->acceptedTypes = acceptedTypes;
	}
private:
	std::string name;
	int acceptedTypes;
};

class pin
{
protected:
	const pinDefinition *definition;
private:
	signal* connectedSignal;
public:
	const signal* GetConnectedSignal() {return connectedSignal;}
};

class outputPin : pin
{
	valueType value;
public:
	outputPin(const pinDefinition *def) { this->definition = def; };
	void SetValue(const valueType& newValue) { value = newValue; }
	valueType GetValue() const { return value; };
	std::vector<inputPin*> connectedPins;
};

class inputPin : pin
{
public:
	inputPin(const pinDefinition* def) { definition = def; connectedPin = nullptr; }
	bool IsConnected() {return connectedPin != nullptr; };
	valueType GetInputValue();
	void SetConnectedPin(const outputPin& pin) { connectedPin = &pin; }
private:
	const outputPin* connectedPin;
};