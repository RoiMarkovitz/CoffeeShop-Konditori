#ifndef __SHIFT_H
#define __SHIFT_H

class Cashier;
class Konditor;

class Shift
{
private:
	Cashier* cashier; // ref
	Konditor* konditor; // ref

public:
	Shift();

	const Cashier* getCashier() const { return cashier; }	
	const Konditor* getKonditor() const { return konditor; }

	void setCashier(Cashier* cashier) noexcept(false);
	void setKonditor(Konditor* konditor) noexcept(false);

	friend ostream& operator<<(ostream& os, const Shift& shift);
};

#endif //__SHIFT_H
