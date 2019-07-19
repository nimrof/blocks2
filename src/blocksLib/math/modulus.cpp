#include "modulus.h"
#include "common.h"
#include "exception.h"

#define OPERATOR std::modulus

modulus::modulus()
{
	inputs.emplace_back(inputPin(&inputDef));
	inputs.emplace_back(inputPin(&inputDef));
	output.emplace_back(outputPin(&sumDef));
}

void modulus::run()
{
	valueType result;
	valueType f = inputs.at(0);

	for(auto i = 1u; i < inputs.size();i++)
	{
		switch (f.index())
		{
		case dt_int:
			result = arithmeticInt<OPERATOR<int>, int>(f, inputs.at(i).GetInputValue());
			break;
		case dt_uint:
			result = arithmeticInt<OPERATOR<unsigned int>, unsigned int>(f, inputs.at(i).GetInputValue());
			break;
		case dt_f32:
		case dt_f64:
		case dt_bool:
		case dt_string:
		case dt_any:
			throw typeNotSupported(f);
			break;
		}
	}
}

block* modulus::Create(const std::vector<pin>& configuration)
{
	return nullptr;
}
