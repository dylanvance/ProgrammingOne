/*
* Program Name: COP 2220 Project 3
*
* Description: Determines the monthly payment and prints the amortization for a loan.
*
* Author: Dylan Vance n01450847
*
* Date: 11/17/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DUR_MIN 4
#define DUR_MAX 40
#define AMT_MIN 10000
#define AMT_MAX 2000000
#define INT_MIN 1
#define INT_MAX 20


void GetLoanDuration(int*);
void GetLoanAmount(int*);
void GetInterest(float*);
float CalcMonthlyPay(float, float, float);
void OutputAmortization(int, int, float, float);


int main(void) {

	int loanDur = 0;
	int loanAmt = 0;
	float interest = 0.0;
	float monthlyPayment;

	while (1 > 0) {

		printf("Note: Enter '0' for any term to quit\n");
		GetLoanDuration(&loanDur);
		GetLoanAmount(&loanAmt);
		GetInterest(&interest);

		if (loanDur == 0 || loanAmt == 0 || interest == 0) {
			printf("Program Terminated\n");
			break;
		}

		monthlyPayment = CalcMonthlyPay(loanAmt, loanDur, interest);
		printf("Monthly Payment: %.2f\n", monthlyPayment);

		OutputAmortization(loanDur, loanAmt, interest, monthlyPayment);

	}
  	
	return 0;
}


/*
* Function Name: GetLoanDuration
*
* Input Parameters: A pointer that points to the variable in the function call in main; makes a return statement unnecessary.
*
* Description: Gets input from the user for the duration of the loan in years. Also has a quit function as well as an out of range-detecting function
*
* Return Value: Nothing.
*/
void GetLoanDuration(int* durPtr) {

	printf("Enter the duration of the loan in years (4 to 40): ");
	scanf("%d", durPtr);

	if (*durPtr == 0) {
		return;
	}

	if (*durPtr < DUR_MIN || *durPtr > DUR_MAX) {
		printf("Invalid Entry. Please Try Again\n");
		GetLoanDuration(durPtr);
	}

	*durPtr *= 12; //convert years to months
}


/*
* Function Name: GetLoanAmount
*
* Input Parameters: A pointer that points to the variable in the function call in main; makes a return statement unnecessary.
*
*
* Description: Same as the above function except it gets the amount of the loan.
*
* Return Value: Nothing.
*/
void GetLoanAmount(int* amtPtr) {

	printf("Enter the loan amount (10,000 to 2,000,000) (exclude commas): ");
	scanf("%d", amtPtr);

	if (*amtPtr == 0) {
		return;
	}

	if (*amtPtr < AMT_MIN || *amtPtr > AMT_MAX) {
		printf("Invalid Entry. Please Try Again\n");
		GetLoanAmount(amtPtr);
	}
}


/*
* Function Name: GetInterest
*
* Input Parameters: A pointer that points to the variable in the function call in main; makes a return statement unnecessary.
*
*
* Description: Same as the above function except it gets the percent interest on the loan
*
* Return Value: Nothing.
*/
void GetInterest(float* intPtr) {

	printf("Enter the annual interest rate (1 to 20) (exclude percent symbol): ");
	scanf("%f", intPtr);

	if (*intPtr == 0) {
		return;
	}

	if (*intPtr < INT_MIN || *intPtr > INT_MAX) {
		printf("Invalid Entry. Please Try Again\n");
		GetInterest(intPtr);
	}

	*intPtr /= 100; //convert percent to decimal
	*intPtr /= 12; //convert from annual to monthly 
}


/*
* Function Name: CalcMonthlyPay
*
* Input Parameters: Three float type variables (loan amount, loan duration, and interest).
*
* Description: Calculates the monthly payment.
*
* Return Value: The monthly payment.
*/
float CalcMonthlyPay(float a, float n, float r) {

	float p;
	float rPlus1 = r + 1;
	float expression1;
	float expression2;

	expression1 = r * pow(rPlus1, n);
	expression2 = pow(rPlus1, n) - 1;

	p = a * (expression1 / expression2);

	return p;
}


/*
* Function Name: OutputAmortization
*
* Input Parameters: Two interger variables and two float variables (duration in years and loan amount; interest and monthly payment).
*
* Description: Prints an amortization table as well as the total amount, total principal, and total interest paid.
*
* Return Value: Nothing.
*/
void OutputAmortization(int dur, int total, float rate, float monthly) {

	float balance = total;
	float interest;
	float principal;
	float totalInterest = 0.0;
	float totalPrincipal = 0.0;
	float totalPaid = 0.0;

	printf("---------------------------------------------\n");
	printf("| Month  | Interest  | Principal | Balance  |\n");
	printf("---------------------------------------------\n");

	for (int i = 1; i <= dur; i++) {
		interest = balance * rate;
		principal = monthly - interest;
		balance -= principal;
		totalInterest += interest;
		totalPrincipal += principal;
		totalPaid += principal + interest;
		printf("| %.3d \t | %6.2f \t | %6.2f \t | %10.2f |\n", i, interest, principal, balance);
		printf("---------------------------------------------\n");
	}

	printf("Total Paid: %.2f\n", totalPaid);
	printf("Total Principal Paid: %.2f\n", totalPrincipal);
	printf("Total Interest Paid: %.2f\n", totalInterest);

	return;
}