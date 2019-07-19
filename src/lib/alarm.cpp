#include "alarm.h"

#include "types.h"
#include "pin.h"
#include "signal.h"

void alarm::SetStatus(bool active)
{
	if (active && IsAlarmInhibited())
	{
		return;
	}
	active = true;

	for (auto func : listeners)
	{
		func(*this, active);
	}
	this->active->SetValue(valueType(active));
}

bool alarm::IsAlarmInhibited() const
{
	if (inhibit->IsConnected())
	{
		try
		{
			if (std::any_cast<bool>(inhibit->GetInputValue()))
			{
				//alarm inhibited
				return true;
			}
		}
		catch (const std::bad_any_cast& e)
		{
			//std::cout << e.what() << '\n';
		}
	}
	return false;
}
