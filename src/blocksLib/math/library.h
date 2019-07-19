#pragma once
#include <vector>
#include "block.h"

#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"
#include "modulus.h"
#include "negate.h"

#include "comparators/compare.h"

std::vector<block*> libraryBlocks{	new add(),
									new subtract(),
									new multiply(),
									new divide(),
									new modulus(),
									new negate() };

const std::vector<block*> getBlocks() { return libraryBlocks; }