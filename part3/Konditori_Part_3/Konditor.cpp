#include "Konditor.h"

Konditor::Konditor(const char* name, double hourlyWage) noexcept(false) : Employee(name, hourlyWage) {}

void Konditor::bake(vector<PastryWithCount*> pastries) const 
{
	vector<PastryWithCount*>::const_iterator itr = pastries.begin();
	vector<PastryWithCount*>::const_iterator itrEnd = pastries.end();
	for (; itr != itrEnd; ++itr)
		(*itr)->setReady(true);
}

void Konditor::toOs(ostream& os) const
{
	os << ", Role: Konditor" << endl;
}
