#pragma once
#include <types.h>
#include <block.h>

class compare : public block
{
public:
	compare();
	void run();
	virtual block* Create(const std::vector<pin>& configuration) override;
	bool IsInputTypesSupported(const std::vector<dataType>& inputTypes);
	virtual std::string GetType() override { return "std.math::compare"; }
private:
	static inline pinDefinition inputDef = pinDefinition("input", dt_numeric | dt_string);
	static inline pinDefinition ltDef = pinDefinition("<", dt_bool);
	static inline pinDefinition eqDef = pinDefinition("==", dt_bool);
	static inline pinDefinition gtDef = pinDefinition(">", dt_bool);
};
