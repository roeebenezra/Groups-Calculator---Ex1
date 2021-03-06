#pragma once 
#include "Macros.hpp"
#include "Set.hpp"
#include "Print.hpp"

class Operation
{

public:
	Operation();
	virtual ~Operation() {}
	void setOperations(const shared_ptr <Operation>&, const shared_ptr <Operation>&);
	shared_ptr <Operation> getLeftOperation()const;
	shared_ptr <Operation> getRightOperation()const;
	virtual vector<int> eval(string&, bool);
	string setPrint(const vector<int>&, string&);
	virtual vector<int> calculate(const vector<int>&, const vector<int>&);
	virtual string addOperation();
	virtual void setOperation(const vector<int>&, const vector<int>&, string&);
	virtual void setComplexOperation(string&, bool);
	virtual void printEx(char&, bool);
	virtual void print(char&) = 0;

private:
	shared_ptr <Operation> m_leftOperation, m_rightOperation;
	Print m_print;
};