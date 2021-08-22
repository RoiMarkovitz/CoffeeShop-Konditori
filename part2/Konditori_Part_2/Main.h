#ifndef __MAIN_H
#define __MAIN_H

#include "Konditori.h"
#include "Address.h"
#include "Employee.h"
#include "Shift.h"
#include "Pastry.h"
#include "Recipe.h"
#include "Ingredient.h"
#include "Bill.h"

const int STR_LEN = 80;

int main();
Konditori initKonditori() noexcept(false);
void mainMenu(Konditori& k);
void editKonditoriInformation(Konditori& k) noexcept(false);
void editKonditoriName(Konditori& k) noexcept(false);
void editKonditoriCity(Address& a) noexcept(false);
void editKonditoriStreet(Address& a) noexcept(false);
void editKonditoriHouseNumber(Address& a) noexcept(false);
void addEmployee(Konditori& k) noexcept(false);
void showEmployees(const Employee*const* employees, int size);
void editShift(Konditori& k);
void showShift(const Shift& shift);
void addPastry(Konditori& k) noexcept(false);
Recipe initRecipeFromUser() noexcept(false);
Ingredient initIngredientFromUser() noexcept(false);
void editPastry(Konditori& k) noexcept(false);
void editPastryMenu(Konditori& k, Pastry& p) noexcept(false);
void printPastryActionStatus(Konditori::ePastryActionStatus status);
void showPastry(const Konditori& k);
void showBills(const Konditori& k);
void printBills(const Bill*const* bills, int size);
void shop(Konditori& k);

#endif //__MAIN_H