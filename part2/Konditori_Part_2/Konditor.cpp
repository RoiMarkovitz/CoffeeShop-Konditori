#include "Konditor.h"

Konditor::Konditor(const char* name, double hourlyWage) noexcept(false) : Employee(name, hourlyWage) {}

void Konditor::bake(PastryWithCount*const* pastries, int logicalSize) const 
{
	for (int i = 0; i < logicalSize; i++)
		pastries[i]->setReady(true);
}

void Konditor::toOs(ostream& os) const
{
	os << ", Role: Konditor" << endl;
}
