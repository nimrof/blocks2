#pragma once
#include <types.h>
#include <block.h>

class multiply : public block
{
public:
	multiply();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	virtual std::string GetType() override { return "std.math::multiply"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_numeric);
	static inline pinDefinition sumDef = pinDefinition("sum", dt_numeric);
};