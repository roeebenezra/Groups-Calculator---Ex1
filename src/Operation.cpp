#include "Operation.hpp"

//____________________
Operation::Operation()
{
	m_leftOperation = nullptr;
	m_rightOperation = nullptr;
}
//___________________________________________________________________________________________________
void Operation::setOperations(const shared_ptr <Operation>& left,const shared_ptr <Operation>& right)
{
	m_leftOperation = left;
	m_rightOperation = right;
}
//_______________________________________________________
shared_ptr <Operation> Operation::getLeftOperation()const
{
	return m_leftOperation;
}
//________________________________________________________
shared_ptr <Operation> Operation::getRightOperation()const
{
	return m_rightOperation;

}

// print of the expresion of this current operation
//________________________________________________
void Operation::printEx(char& capitle, bool first)
{
	if (this->m_leftOperation != nullptr && this->m_rightOperation != nullptr)
	{
		if (first)
			cout << "(";
		this->m_leftOperation->printEx(capitle, first);
		if (first)
			cout << this->addOperation();
		this->m_rightOperation->printEx(capitle, first);
		if (first)
			cout << ")";
	}
	else
	{
		first = false;
		this->print(capitle);
	}
}

//evaluate operation 
//_______________________________________________________
vector<int> Operation::eval(string& groups, bool complex)
{
	if (this->m_leftOperation != nullptr && this->m_rightOperation != nullptr)
	{
		vector<int> a = this->m_leftOperation->eval(groups, complex);
		if (complex)
			setComplexOperation(groups, true);
		vector<int> b = this->m_rightOperation->eval(groups, complex);
		if (complex)
			setComplexOperation(groups, false);
		return calculate(a, b);
	}
	else
	{
		complex = false;
		Set a, b;
		setOperation(a.getArr(), b.getArr(), groups);
		return calculate(a.getArr(), b.getArr());
	}
}
//_________________________________________________________________________________
void Operation::setOperation(const vector<int>& a, const vector<int>& b, string& s)
{
	string operation1, operation2;
	s += "(" + setPrint(a, operation1) + addOperation() + setPrint(b, operation2) + ")";
}
//_________________________________________________________
string Operation::setPrint(const vector<int>& a, string& s)
{
	return m_print.setGroup(a, s);
}
//________________________________________________________
void Operation::setComplexOperation(string& s, bool start)
{
	string operation;
	if (start)
	{
		operation = "(" + s + addOperation();
		s = operation;
	}
	else
	{
		operation += s + ")";
		s = operation;
	}
}
//__________________________________________________________________________
vector<int> Operation::calculate(const vector<int>& a, const vector<int>& b)
{
	return a;
}
//______________________________
string Operation::addOperation()
{
	return "";
}