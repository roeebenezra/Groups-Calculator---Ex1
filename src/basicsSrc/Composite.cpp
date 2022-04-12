#include "basicsInc/Composite.hpp"

//________________________________________________
void Composite::printEx(char& capitle, bool first)
{
	if (this->getLeftOperation() != nullptr && this->getRightOperation() != nullptr)
	{
		this->getLeftOperation()->printEx(capitle, first);
		if (first)
			cout << this->addOperation();
		this->getRightOperation()->printEx(capitle, first);
	}
	else
	{
		first = false;
		this->print(capitle);
	}
}
//_______________________________________________________
vector<int> Composite::eval(string& groups, bool complex)
{
	bool composite = true;
	vector<int> a = evalComp(this->getLeftOperation(), groups, complex, composite, a);
	if (complex)
		setComplexOperation(groups, true);
	composite = false;
	vector<int> b = evalComp(this->getRightOperation(), groups, complex, composite, a);
	if (complex)
		setComplexOperation(groups, false);
	return this->getRightOperation()->calculate(a, b);
}
//evaluate of composite operation
//_____________________________________________________________________________________
vector<int> Composite::evalComp(const shared_ptr <Operation>& operation, string& groups,
	bool complex, bool& composite, const vector<int>& leftCompArr)
{
	if (operation->getLeftOperation() != nullptr && operation->getRightOperation() != nullptr)
	{
		vector<int> a = evalComp(this->getLeftOperation(), groups, complex, composite, leftCompArr);
		vector<int> b = evalComp(this->getRightOperation(), groups, complex, composite, leftCompArr);
		return operation->calculate(a, b);
	}
	else
	{
		if (composite)
		{
			complex = false;
			Set a, b;
			operation->setOperation(a.getArr(), b.getArr(), groups);
			return operation->calculate(a.getArr(), b.getArr());
		}
		else
		{
			composite = true;
			Set b;
			operation->setOperation(leftCompArr, b.getArr(), groups);
			return operation->calculate(leftCompArr, b.getArr());
		}
	}
}
//______________________________
string Composite::addOperation()
{
	return " -> ";
}
//__________________________________
void Composite::print(char& capitle)
{
	cout << "(" << ++capitle << " -> " << ++capitle << ")";
}