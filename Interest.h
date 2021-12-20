#ifndef INTEREST_H
#define INTEREST_H

class Interest
{
public:
	void SetInitAmount(double dollars);
	void SetYears(int years);
	void SetDeposit(double deposits);
	void SetInterestRate(double rate);
	void PrintInput() const;
	void PrintInputBlank() const;
	void PrintAddHeader() const;
	void PrintNoAddHeader() const;
	void PrintYearlyBalance(int year, double balance, double interest) const;

private:
	double initAmount;
	int months;
	int years;
	double percentage;
	double deposits;

};


#endif // !INTEREST_H


