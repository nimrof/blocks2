#pragma once
#include <types.h>
#include <block.h>

class add : public block
{
public:
	add();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	virtual std::string GetType() override { return "std.math::add"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_numeric);
	static inline pinDefinition sumDef = pinDefinition("sum", dt_numeric);
};