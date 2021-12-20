#include "Interest.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include <iomanip>
using namespace std;

// Chaz Burkhart


void InterestCalculator() {
	double initialAmount;						// Setting Variables
	double monthlyInitial;
	double monthlyDeposit;
	double interestRate;
	int years;
	double monthlyInterest;
	double yearlyInterest;
	double monthlyBalance;
	double yearlyBalance;
	int i;
	int j;
	string input;

	Interest amount{};
	amount.PrintInputBlank();						// Printing Input Display Template

	cout << endl << endl;
	
	cout << "Initial Investment Amount : ";		// Getting Initial Amount
	cin >> initialAmount;

	if (initialAmount >= 0) {					// Checking if Initial Amount is Positive

		cout << endl;

		cout << "Monthly Deposit : ";			// Getting Monthly Deposit Amount
		cin >> monthlyDeposit;

		cout << endl;

		cout << "Annual Interest : ";			// Getting Interest Amount
		cin >> interestRate;

		cout << endl;

		cout << "Number of years : ";			// Getting Number of Years
		cin >> years;

		if (years > 0) {						// Checking if Years is Positive
			system("cls");
			
			amount.SetInitAmount(initialAmount);			// Calling Inital Amount
			amount.SetDeposit(monthlyDeposit);				// Calling Additional Deposit Amounts
			amount.SetInterestRate(interestRate);			// Calling Interest Rate Amount
			amount.SetYears(years);							// Calling Number of Years
			amount.PrintInput();									// Printing Inputs

			cout << endl << endl;

			cout << "Press any key to continue..." << endl;	// Getting User To Change Screens
			cin >> input;
			system("cls");									// Clearing Screen
			
			amount.PrintNoAddHeader();						// Printing Header for no monthly deposits

			monthlyBalance = initialAmount;
			yearlyBalance = initialAmount;

			for (i = 0; i < years; ++i) {												// For Loop to get balances without adding monthly
				monthlyInitial = yearlyBalance;
				for (j = 0; j < 12; ++j) {
					monthlyInterest = (monthlyBalance) * ((interestRate / 100) / 12);	// Interest Rate Calculation
					monthlyBalance = monthlyBalance + monthlyInterest;					// Monthly Balance Calculation
				}

				yearlyBalance = monthlyBalance;											// Getting New Yearly Balance
				yearlyInterest = yearlyBalance - monthlyInitial;						// Calculating Yearly Interest

				amount.PrintYearlyBalance(i + 1, yearlyBalance, yearlyInterest);		// Calling Print After Each Year
			}

			cout << endl << endl << endl;
			amount.PrintAddHeader();					// Printing Header for adding monthly deposits

			monthlyBalance = initialAmount;
			yearlyBalance = initialAmount;

			for (i = 0; i < years; ++i) {												// For Loop to get balances with adding monthly
				monthlyInitial = yearlyBalance;
				for (j = 0; j < 12; ++j) {
					monthlyInterest = (monthlyBalance + monthlyDeposit) * ((interestRate / 100) / 12);	// Interest Rate Calculation
					monthlyBalance = monthlyBalance + monthlyInterest + monthlyDeposit;					// Monthly Balance Calculation
				}

				yearlyBalance = monthlyBalance;												// Getting New Yearly Balance
				yearlyInterest = yearlyBalance - monthlyInitial - (monthlyDeposit * 12);	// Calculating Yearly Interest

				amount.PrintYearlyBalance(i + 1, yearlyBalance, yearlyInterest);			// Calling Print After Each Year

			}
			return;
		}
		else {								// Reporting Years can't be negative
			system("cls");

			cout << "Years must be a positive non-zero number." << endl;
			cout << endl << endl;
			return;							// Loop back to beginning
		}
	}
	else {									// Reporting Initial Investment can't be negative
		system("cls");

		cout << "Initial amount must be a non-negative value." << endl;
		cout << endl << endl;
		return;								// Loop back to beginning
	}
	
	return;
}


int main() {											// Main Function
	char input = 'y';
	

	while (input == 'y') {								// While Loop to continue testing different numbers
		system("cls");
		InterestCalculator();							// Function to start calculator

		cout << endl << endl << endl;
		cout << "Press Y to continue..." << endl;			// Checking if user wishes to continue
		cin >> input;
	}
	
	return 0;
}