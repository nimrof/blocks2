#pragma once
#include <exception>

class typeNotSupported : std::exception
{
public:
	typeNotSupported(const valueType& type) {};
};