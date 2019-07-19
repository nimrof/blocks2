#pragma once
#include <types.h>
#include <block.h>

class subtract : public block
{
public:
	subtract();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	virtual std::string GetType() override { return "std.math::subtract"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_numeric);
	static inline pinDefinition sumDef = pinDefinition("sum", dt_numeric);
};