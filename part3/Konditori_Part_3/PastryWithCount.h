#ifndef __PASTRYWITHCOUNT_H
#define __PASTRYWITHCOUNT_H

#include "Pastry.h"

class PastryWithCount
{
private:
	Pastry pastry;
	int amount;
	bool isReady;

public:
	PastryWithCount(const Pastry& pastry, int amount = 1) noexcept(false);
	PastryWithCount(Pastry&& pastry, int amount = 1) noexcept(false);
	
	const Pastry& getPastry() const { return pastry; }
	int getAmount() const { return amount; }
	bool getIsReady() const { return isReady; }	
	double getPrice() const;
	
	void setPastry(const Pastry& pastry);
	void setAmount(int amount) noexcept(false);
	void setReady(bool isReady);

	friend ostream& operator<<(ostream& os, const PastryWithCount& pastryWithCount);
};

#endif //__PASTRYWITHCOUNT_H