#pragma once
#include "Macros.hpp"

class Print
{
public:
	Print(){}
	void printHelp();
	string setGroup(const vector<int>&, string&);
	void printArr(vector<int>&);
};
