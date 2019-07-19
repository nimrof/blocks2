#pragma once
#include <types.h>
#include <block.h>

class negate : public block
{
public:
	negate();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	virtual std::string GetType() override { return "std.math::negate"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_signed_numeric);
	static inline pinDefinition sumDef = pinDefinition("sum", dt_signed_numeric);
};