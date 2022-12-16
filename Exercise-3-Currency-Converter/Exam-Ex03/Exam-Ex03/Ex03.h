#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <map>
#include <set>

class CurrencyConverter {
private:
	std::set<std::string> currencies;
	std::map<std::string, double> currencyToExchangeRate;

	double serve(double, std::string, double(*func1)(double, double));

public:
	CurrencyConverter();
	bool supportsCurrency(std::string);
	void print();
	bool addCurrency(std::string , double);
	bool updateExchangeRate(std::string , double);
	double convertToDKK(double , std::string);
	double convertFromDKK(double , std::string);
};

#endif