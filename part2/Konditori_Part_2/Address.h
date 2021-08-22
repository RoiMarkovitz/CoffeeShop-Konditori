#ifndef __ADDRESS_H
#define __ADDRESS_H

class Address
{
private:
	char* city;
	char* street;
	int streetNumber;

public:
	Address(const char* cityName, const char* streetName, int streetNumber) noexcept(false);
	Address(const Address& other);
	Address(Address&& other) noexcept;
	~Address();

	const Address& operator=(const Address& other);
	const Address& operator=(Address&& other) noexcept;

	const char* getCity() const { return city; }
	const char* getStreet() const { return street; }
	int getStreetNumber() const { return streetNumber; }

	void setCity(const char* cityName) noexcept(false);
	void setStreet(const char* streetName) noexcept(false);
	void setStreetNumber(int streetNumber) noexcept(false);

	friend ostream& operator<<(ostream& os, const Address& address);
};


#endif //__ADDRESS_H
