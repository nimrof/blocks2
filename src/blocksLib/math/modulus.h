#pragma once
#include <types.h>
#include <block.h>

class modulus : public block
{
public:
	modulus();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	virtual std::string GetType() override { return "std.math::modulus"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_integer);
	static inline pinDefinition sumDef = pinDefinition("sum", dt_integer);
};