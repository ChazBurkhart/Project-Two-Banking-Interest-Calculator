#include "Interest.h"
#include <iostream>
#include <iomanip>
using namespace std;


void Interest::SetInitAmount(double dollars)
{
	initAmount = dollars;
}

void Interest::SetDeposit(double monthlyDeposits)
{
	deposits = monthlyDeposits;
}

void Interest::SetInterestRate(double rates)
{
	percentage = rates;
}

void Interest::SetYears(int numYears)
{
	years = numYears;
}



// Printing the template with the users inputs

void Interest::PrintInput() const 
{
	cout.precision(2);

	cout << "***********************************" << endl;
	cout << "********** Data Input *************" << endl;
	cout << fixed << "Initial Investment Amount:   $" << initAmount << endl;
	cout << "Monthly Deposit:   $"  << deposits << endl;
	cout << "Annual Interest:   " << percentage << "%" << endl;
	cout << "Number of Years:   " << years << endl;
}



// Printing the blank template

void Interest::PrintInputBlank() const
{
	cout << "***********************************" << endl;
	cout << "********** Data Input *************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of Years:" << endl;
}



// Printing the header for the additional deposits balances

void Interest::PrintAddHeader() const
{
	cout << "  Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "===========================================================" << endl;
	cout << setw(6) << "Year";
	cout << setw(21) << "Year End Balance";
	cout << setw(30) << "Year End Earned Interest" << endl;
	cout << "___________________________________________________________" << endl;
}



// Printing Header for the no additional deposits balances

void Interest::PrintNoAddHeader() const
{
	cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "===========================================================" << endl;
	cout << setw(6) << "Year";
	cout << setw(21) << "Year End Balance";
	cout << setw(30) << "Year End Earned Interest" << endl;
	cout << "___________________________________________________________" << endl;
}



// Printing the yearly balance for each year

void Interest::PrintYearlyBalance(int year, double balance, double interest) const
{
	cout.precision(2);
	cout << setw(6) << year;
	cout << setw(21) << fixed << balance;
	cout << setw(30) << interest << endl;

}