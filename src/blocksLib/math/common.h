#pragma once
#include <types.h>
#include <exception.h>

template <typename mathOperator, typename T>
T arithmetic(valueType val1, valueType val2)
{
	switch (val2.index())
	{
	case dt_int:
		return mathOperator()(std::get <T>(val1), (T)std::get<int>(val2));
		break;
	case dt_uint:
		return mathOperator()(std::get <T>(val1), (T)std::get<unsigned int>(val2));
		break;
	case dt_f32:
		return mathOperator()(std::get <T>(val1), (T)std::get<float>(val2));
		break;
	case dt_f64:
		return mathOperator()(std::get <T>(val1), (T)std::get<double>(val2));
		break;
	case dt_bool:
	case dt_string:
	case dt_any:
		throw typeNotSupported(val2);
		break;
	}
	return 0;
}

template <typename mathOperator, typename T>
T arithmeticInt(valueType val1, valueType val2)
{
	switch (val2.index())
	{
	case dt_int:
		return mathOperator()(std::get <T>(val1), (T)std::get<int>(val2));
		break;
	case dt_uint:
		return mathOperator()(std::get <T>(val1), (T)std::get<unsigned int>(val2));
		break;
	case dt_f32:
	case dt_f64:
	case dt_bool:
	case dt_string:
	case dt_any:
		throw typeNotSupported(val2);
		break;
	}
	return 0;
}

template <typename mathOperator, typename T>
T arithmeticSingel(valueType val)
{
	switch (val.index())
	{
	case dt_int:
	case dt_uint:
	case dt_f32:
	case dt_f64:
		return mathOperator()(std::get <T>(val));
		break;
	case dt_bool:
	case dt_string:
	case dt_any:
		throw typeNotSupported(val);
		break;
	}
	return 0;
}

template <typename comparator, typename T>
bool comparison(T val1, valueType val2)
{
	switch (val2.index())
	{
	case dt_int:
		return comparator()(val1, (T)std::get<int>(val2));
		break;
	case dt_uint:
		return comparator()(val1, (T)std::get<unsigned int>(val2));
		break;
	case dt_f32:
		return comparator()(val1, (T)std::get<float>(val2));
		break;
	case dt_f64:
		return comparator()(val1, (T)std::get<double>(val2));
		break;
	case dt_bool:
	case dt_string:
	case dt_any:
		throw typeNotSupported(val2);
		break;
	}
	return 0;
}

template <typename comparator>
bool comparison(std::string val1, valueType val2)
{
	switch (val2.index())
	{
	case dt_string:
		return comparator()(val1, std::get<std::string>(val2));
	case dt_int:
	case dt_uint:
	case dt_f32:
	case dt_f64:
	case dt_bool:
	case dt_any:
		throw typeNotSupported(val2);
		break;
	}
	return 0;
}
