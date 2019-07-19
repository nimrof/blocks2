#pragma once
#include <any>
#include <string>
#include <variant>

struct version
{
	int major;
	int minor;
};

typedef std::variant<bool,
	int,
	unsigned int,
	float,
	double,
	std::string,
	std::any> valueType;

enum dataType
{
	dt_bool = 1 << 0,
	dt_int = 1 << 1,
	dt_uint = 1 << 2,
	dt_f32 = 1 << 3,
	dt_f64 = 1 << 4,
	dt_string = 1 << 5,
	dt_any = 1 << 6,
};

inline dataType operator|(dataType a, dataType b) noexcept
{
	return static_cast<dataType>(static_cast<int>(a) | static_cast<int>(b));
}

const dataType dt_numeric = dt_int | dt_uint | dt_f32 | dt_f64;
const dataType dt_signed_numeric = dt_int | dt_f32 | dt_f64;
const dataType dt_integer = dt_int | dt_uint;