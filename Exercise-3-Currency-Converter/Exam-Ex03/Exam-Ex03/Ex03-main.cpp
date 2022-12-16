#include <iostream>
#include "Ex03.h"

int main() {
	CurrencyConverter currencyConverter;

	std::cout << "addCurrency(\"EUR\" , 7.44416);"  << std::endl;
	currencyConverter.addCurrency("EUR", 7.44416);
	currencyConverter.print();

	std::cout << std::endl;

	std::cout << "addCurrency(\"EUR\" , 17.44416);" << std::endl;
	currencyConverter.addCurrency("EUR", 17.44416);
	currencyConverter.print();

	std::cout << std::endl;

	std::cout << "addCurrency(\"USD\" , 16.31708);" << std::endl;
	currencyConverter.addCurrency("USD", 16.31708);
	currencyConverter.print();

	std::cout << std::endl;

	std::cout << "updateExchangeRate(\"USD\" , 6.31708);" << std::endl;
	currencyConverter.updateExchangeRate("USD", 6.31708);
	currencyConverter.print();

	std::cout << '\n' << std::endl;

	double amountDKK = 100;
	double amountEUR = currencyConverter.convertFromDKK(amountDKK, "EUR");

	std::cout << amountDKK << " DKK = " << amountEUR << " EUR" << std::endl;

	amountDKK = currencyConverter.convertToDKK(amountEUR, "EUR");

	std::cout << amountEUR << " EUR = " << amountDKK << " DKK" << std::endl;

	return 0;
}