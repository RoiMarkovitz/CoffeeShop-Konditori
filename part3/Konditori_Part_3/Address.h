#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <string>

class Address
{
private:
	string city;
	string street;
	int streetNumber;

public:
	Address(const string& cityName, const string& streetName, int streetNumber) noexcept(false);
	Address(const Address& other) = default;
	Address(Address&& other) noexcept;

	const Address& operator=(Address&& other) noexcept;

	const string& getCity() const { return city; }
	const string& getStreet() const { return street; }
	int getStreetNumber() const { return streetNumber; }

	void setCity(const string& cityName) noexcept(false);
	void setStreet(const string& streetName) noexcept(false);
	void setStreetNumber(int streetNumber) noexcept(false);

	friend ostream& operator<<(ostream& os, const Address& address);
};


#endif //__ADDRESS_H
