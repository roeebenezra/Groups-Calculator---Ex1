#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Intersection : public Operation
{
public:
	Intersection() {}
	string addOperation()override;
	void print(char&)override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
