#include "negate.h"
#include "common.h"
#include "exception.h"

#define OPERATOR std::negate

negate::negate()
{
	inputs.emplace_back(inputPin(&inputDef));
	output.emplace_back(outputPin(&sumDef));
}

void negate::run()
{
	valueType result;
	valueType f = inputs.at(0);

	switch (f.index())
	{
	case dt_int:
		result = arithmeticSingel<OPERATOR<int>, int>(f);
		break;
	case dt_f32:
		result = arithmeticSingel<OPERATOR<float>, float>(f);
		break;
	case dt_f64:
		result = arithmeticSingel<OPERATOR<double>, double>(f);
		break;
	case dt_uint:
	case dt_bool:
	case dt_string:
	case dt_any:
		throw typeNotSupported(f);
		break;
	}
}

block* negate::Create(const std::vector<pin>& configuration)
{
	return nullptr;
}
