#include <iostream>
#include "ex03.h"


// NOTE:
// I have changed names to shorter ones to make code more compact.


// Do not modify
CurrencyConverter::CurrencyConverter() {
	currencies.insert("DKK");
	currencyToExchangeRate["DKK"] = 1;
}


// Do not modify
bool CurrencyConverter::supportsCurrency(std::string currency) {
	if (currencies.find(currency) != currencies.end())
		return true;
	else
		return false;
}



/////////////////////////////////////////////////////////////////////////////
// Exercise 3 (a) Check and correct if necessary
/////////////////////////////////////////////////////////////////////////////

// ORIGINAL CODE:
/*void CurrencyConverter::print() {
	cout << "The converter supports the following currencies:" << endl;
	for (map<string, double>::iterator it = currencyToExchangeRate.begin();
		 it != currencyToExchangeRate.end(); ++it) {
		cout << ’ ’ << "currency " << it->second << " has exchange rate " 
		     << it->first << endl;
	}
}*/

//***************************************************************************
// IMPROVEMENTS:
// The verbose declaration of the iterator can be omitted in the for loop.
// To be more concise and elegant, a range-based for loop is even better.

// ERRORS:
// - The single character delimiter in cout.
// - The map's key and value are printed in reversed order.
//***************************************************************************

// IMPROVED CODE:

void CurrencyConverter::print() {
	std::cout << "Supported currencies:" << std::endl;
	for (auto & c : currencyToExchangeRate) {
		std::cout << ' ' << "currency " << c.first << " has exchange rate ";
		std::cout << c.second << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Exercise 3 (b) Check and correct if necessary
/////////////////////////////////////////////////////////////////////////////


// ORIGINAL CODE
/*bool CurrencyConverter::addCurrency(string currency, double rateToDKK) {
	if (supportsCurrency(currency)) {
		//I already have this element. Hence I return false
		return false;
	}
	else if (rateToDKK <= 0) {            
		//Exchange rates must be positive
		return false;
	}
	else {
		currencies.insert(currency);
		currencyToExchangeRate[rateToDKK] = currency;  // ERROR
		return true;
	}
}*/


//***************************************************************************
// ERROR: 'exchangeRateToDKK' and 'currencyCode' are swapped.
//***************************************************************************


// IMPROVED CODE:

bool CurrencyConverter::addCurrency(std::string currency, double rateToDKK) {
	if (supportsCurrency(currency))
		return false;
	else if (rateToDKK <= 0)
		return false;
	else {
		currencies.insert(currency);
		currencyToExchangeRate[currency] = rateToDKK; 
		return true;
	}
}
















////////////////////////////////////////////////////////////////////////////
// Exercise 3 (c) Implement this function
////////////////////////////////////////////////////////////////////////////
 
// Update the currency exchange rate for an existing currency.
// Though at the exam this would've caused a fail because it was evaluated by
// an automatic test which didn't expect it, it's nice to prompt an error 
// message.

bool CurrencyConverter::updateExchangeRate(std::string currency, double newRate) {
	if (!supportsCurrency(currency)) {
		std::cout << "Currency not supported" << std::endl;
		return false;
	}
	else if (newRate <= 0) {
		std::cout << "Invalid (negative) exchange rate" << std::endl;
		return false;
	}
	else if (currency == "DKK") {
		std::cout << "Cannot update exhange rate for DKK" << std::endl;
		return false;
	}
	else {
		currencyToExchangeRate[currency] = newRate;
		return true;
	}
}



// NOTE:
// The next 2 methods do exactly the same thing except for the operation to
// perform. So, I added an internal method to avoid repeating code. 
// To specify the operation to perform I use a lambda function.


/////////////////////////////////////////////////////////////////////////////
// Exercise 3 (d) Implement this function
/////////////////////////////////////////////////////////////////////////////

// Convert to DKK.

double CurrencyConverter::convertToDKK(double amount, std::string currency) {
	return serve(amount , currency , [](double x , double y){ return x * y; });
}



/////////////////////////////////////////////////////////////////////////////
// Exercise 3 (e) Implement this function
/////////////////////////////////////////////////////////////////////////////

// Convert from DKK to another given currency.

double CurrencyConverter::convertFromDKK(double amountDKK, std::string currency) {
	return serve(amountDKK , currency , [](double x , double y){ return x / y; });
}


double CurrencyConverter::serve(double x, std::string s, double (*f)(double, double)) {
	if (x <= 0)
		return -1;
	else if (!supportsCurrency(s))
		return -1;
	else
		return f(x, currencyToExchangeRate[s]);
}