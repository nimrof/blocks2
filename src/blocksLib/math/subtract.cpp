#include "subtract.h"
#include "common.h"
#include "exception.h"

#define OPERATOR std::minus

subtract::subtract()
{
	inputs.emplace_back(inputPin(&inputDef));
	inputs.emplace_back(inputPin(&inputDef));
	output.emplace_back(outputPin(&sumDef));
}

void subtract::run()
{
	valueType result;
	valueType f = inputs.at(0);

	for(auto i = 1u; i < inputs.size();i++)
	{
		switch (f.index())
		{
		case dt_int:
			result = arithmetic<OPERATOR<int>, int>(f, inputs.at(i).GetInputValue());
			break;
		case dt_uint:
			result = arithmetic<OPERATOR<unsigned int>, unsigned int>(f, inputs.at(i).GetInputValue());
			break;
		case dt_f32:
			result = arithmetic<OPERATOR<float>, float>(f, inputs.at(i).GetInputValue());
			break;
		case dt_f64:
			result = arithmetic<OPERATOR<double>, double>(f, inputs.at(i).GetInputValue());
			break;
		case dt_bool:
		case dt_string:
		case dt_any:
			throw typeNotSupported(f);
			break;
		}
	}
}

block* subtract::Create(const std::vector<pin>& configuration)
{
	return nullptr;
}
