#include "basicsInc/Difference.hpp"

//_______________________________
string Difference::addOperation()
{
	return " - ";
}
//calculate of difference operation
vector<int> Difference::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_difference(a, b, std::back_inserter(result));
	
	return result;
}
//___________________________________
void Difference::print(char& capitle)
{
	cout << "(" << ++capitle << " - " << ++capitle << ")";
}