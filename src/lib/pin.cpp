#include "pin.h"

valueType inputPin::GetInputValue()
{
	if (connectedPin)
	{
		return connectedPin->GetValue();
	}
	return valueType();
}
