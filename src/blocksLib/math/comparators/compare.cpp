#include "compare.h"
#include "../common.h"
#include "exception.h"

compare::compare()
{
}

bool compare::IsInputTypesSupported(const std::vector<dataType> &inputTypes)
{
	if (inputTypes.empty())
	{
		return true;
	}
	//TODO: check individual supported types on input

	dataType firstType = inputTypes[0];
	for (auto t : inputTypes)
	{
		//make sure string only works with string and numeric with numeric
		if (firstType == dt_string && t != dt_string)
		{
			return false;
		}
		else if (t == dt_string)
		{
			return false;
		}
	}
	return true;
}

void compare::run()
{
	valueType val1 = inputs.at(0);
	valueType val2 = inputs.at(1);

	bool result_lt;
	switch (val1.index())
	{
	case dt_int:
		result_lt = comparison<std::less<int> >(std::get <int>(val1), val2);
		break;
	case dt_uint:
		result_lt = comparison<std::less<unsigned int>>(std::get <unsigned int>(val1), val2);
		break;
	case dt_f32:
		result_lt = comparison<std::less<float>>(std::get <float>(val1), val2);
		break;
	case dt_f64:
		result_lt = comparison<std::less<double>>(std::get <double>(val1), val2);
		break;
	case dt_string:
		if (val2.index() != dt_string)
		{
			throw typeNotSupported(val2);
		}
		result_lt = comparison<std::less<std::string>>(std::get <std::string>(val1), val2);
		break;
	case dt_bool:
	case dt_any:
	default:
		throw typeNotSupported(val1);
		break;
	}

	bool result_gt;
	switch (val1.index())
	{
	case dt_int:
		result_gt = comparison<std::greater<int> >(std::get <int>(val1), val2);
		break;
	case dt_uint:
		result_gt = comparison<std::greater<unsigned int>>(std::get <unsigned int>(val1), val2);
		break;
	case dt_f32:
		result_gt = comparison<std::greater<float>>(std::get <float>(val1), val2);
		break;
	case dt_f64:
		result_gt = comparison<std::greater<double>>(std::get <double>(val1), val2);
		break;
	case dt_string:
		if (val2.index() != dt_string)
		{
			throw typeNotSupported(val2);
		}
		result_gt = comparison<std::greater<std::string>>(std::get <std::string>(val1), val2);
		break;
	case dt_bool:
	case dt_any:
	default:
		throw typeNotSupported(val1);
		break;
	}

	output[0].SetValue(result_gt);
	output[1].SetValue(!(result_gt || result_lt));
	output[2].SetValue(result_lt);
}

block* compare::Create(const std::vector<pin>& configuration)
{
	auto ptr = new compare();
	ptr->inputs.emplace_back(inputPin(&inputDef));
	ptr->inputs.emplace_back(inputPin(&inputDef));
	ptr->output.emplace_back(outputPin(&ltDef));
	ptr->output.emplace_back(outputPin(&eqDef));
	ptr->output.emplace_back(outputPin(&gtDef));
	return ptr;
}
