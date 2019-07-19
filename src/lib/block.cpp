#include "block.h"

bool block::IsInputTypesSupported(const std::vector<dataType>& inputTypes)
{
	return false;
}

void block::SetAlarmStatus(alarm& a, bool active)
{
	a.SetStatus(active);
}
