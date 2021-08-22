#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#include "Address.h"
#include "StringUtil.h"

Address::Address(const char* cityName, const char* streetName, int streetNumber) noexcept(false) : city(nullptr), street(nullptr)
{
	setStreetNumber(streetNumber);
	setCity(cityName);

	if (StringUtil::isValidName(streetName))
	{
		delete[] this->street;
		this->street = new char[strlen(streetName) + 1];
		strcpy(this->street, streetName);
	}
	else
	{
		delete[] this->city;
		throw "Error: invalid street name";
	}
}

Address::~Address()
{
	delete[]city;
	delete[]street;
}

Address::Address(const Address& other) : city(nullptr), street(nullptr)
{
	*this = other;
}

Address::Address(Address&& other) noexcept
{
	*this = std::move(other);
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		setCity(other.city);
		setStreet(other.street);
		streetNumber = other.streetNumber;
	}
	return *this;
}

const Address& Address::operator=(Address&& other) noexcept
{
	if (this != &other)
	{
		swap(city, other.city);
		swap(street, other.street);
		streetNumber = other.streetNumber;
	}
	return *this;
}

void Address::setCity(const char* cityName) noexcept(false)
{

	if (StringUtil::isValidName(cityName))
	{
		delete[] this->city;
		this->city = new char[strlen(cityName) + 1];
		strcpy(this->city, cityName);
	}
	else
		throw "Error: invalid city name";
}

void Address::setStreet(const char* streetName) noexcept(false)
{
	if (StringUtil::isValidName(streetName))
	{
		delete[] this->street;
		this->street = new char[strlen(streetName) + 1];
		strcpy(this->street, streetName);
	}
	else
		throw "Error: invalid street name";
}

void Address::setStreetNumber(int streetNumber) noexcept(false)
{
	if (streetNumber <= 0)
		throw "Error: invalid street number";

	this->streetNumber = streetNumber;
}

ostream& operator<<(ostream& os, const Address& address)
{
	os << address.street << " " << address.streetNumber << ", " << address.city << endl;
	return os;
}


