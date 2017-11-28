//Ben Scherer
// 7/7/2017
// Restaurant Functions
// User picks menu items, to generate a total cost.  Then tax and tip are added in.   Finally the bill is paid and change returned 

//Headers to include
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits


using namespace std;

//Functions
double getAmtTendered(string questionToAsk,  double totalBill); //Gets amount tendered and does input validation
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange); //Generic input function. Does input validation and returns int
void displayBill(double bill, double totalBill, double totalTax, double totalTip); // Displays bill using already calculated values
void displayChange(double amtTendered, double totalBill); // Calculates change and displays information about amount tendered/change due
double itemCost(int itemChoice);  //Returns cash value of menu choice
void pauseProgram(); //Pauses program
double getOrder();  //  Returns cash value of menu choice
void displayMenu(); //Displays menu choices
	

//Main function of program
int main() {
	//constants
	const double taxRate = 0.065; //Sales tax 
	const double tipPercent = 0.2; //Percentage to tip
	
	//variables
	double bill; //Total value of all menu items selected
	double totalTax; //tax due
	double totalTip; //tip amount
	double totalBill; //total bill with tax and tip added
	double amtTendered = 0.0; //cach provided to pay bill
	

	//Calculate Bill
	bill = getOrder(); //Get input from user and calculate total
	totalTax = bill * taxRate;
	totalTip = bill * tipPercent;
	totalBill = bill + totalTax + totalTip;

	//Display Bill
	displayBill(bill,totalBill,totalTax,totalTip);

	//Payment
	amtTendered = getAmtTendered("Amount Tendered: ",  totalBill);
	displayChange(amtTendered,totalBill);
	
	
	pauseProgram(); //Pause program so that results can be viewed
	return 0;
}

void displayBill(double bill, double totalBill, double totalTax, double totalTip) {
	cout << "--------------------------------------------------------\n"
		<< setw(30) << "Final Bill " << endl
		<< "--------------------------------------------------------\n"
		<< setw(30) << "Bill: $" << setprecision(2) << fixed << bill << endl
		<< setw(30) << "Tax: $" << setprecision(2) << totalTax  << endl
		<< setw(30) << "Tip: $" << setprecision(2) << totalTip  << endl
		<< setw(30) << "Total Bill: $" << setprecision(2) << totalBill  << endl
		;

}



void displayChange(double amtTendered, double totalBill) {
	double changeDue = amtTendered - totalBill;
	cout << setw(30) << "Amount Tendered: $" << setprecision(2) << amtTendered << endl
		<< setw(30) << "Change Due: $" << setprecision(2) << changeDue << endl
		;


}
double getOrder() { //returns total before tax/tip
	int menuChoice;
	double bill = 0.00;
	displayMenu();
	do {
		menuChoice = getInput("Enter Menu Item: ", "ERROR: Enter a choice between 1-8", 1, 8);
		bill += itemCost(menuChoice);
	} while (menuChoice < 8);
	return bill;
}

double itemCost(int itemChoice) { //Returns cash value of menu choice
	switch (itemChoice) {
		case 1: return 7.00;
		case 2: return 3.00;
		case 3: return 1.75;
		case 4: return 3.25;
		case 5: return 1.50;
		case 6: return 4.25;
		case 7: return 1.00;
		default: return 0.00;
	}

}

//Simple funciton.  Pauses program execution and waits for input
void pauseProgram() {
	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}


void displayMenu() { //Displays food menu
	cout << "Generic Ballpark Snack Shack Gourmet Menu\n" 
		<<  "1 - Beer " << "$7.00\n"
		<< "2 - Soda " << "$3.00\n"
		<<  "3 - Chips " << "$1.75\n"
		<< "4 - Pizza " << "$3.25\n"
		<<  "5 - Hotdog " << "$1.50\n"
		<< "6 - Cheesburger " << "$4.25\n"
		<<  "7 - Water " << "$1.00\n"
		<<  "8 - End Order\n "
		;
}


//simple input validation.  returns double
double getAmtTendered(string questionToAsk, double totalBill) {
	double amtTendered;
	cout << questionToAsk;
	while (!(cin >> amtTendered) || amtTendered < totalBill) {
		if (cin.fail())
			cout << "Enter a valid dollar amount\n";
		else if (amtTendered < totalBill)
			cout << "Amount paid is lower than total bill.  Please enter a new amount\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return amtTendered;
}

//Validates input based on a range.  returns int
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange) {
	int usrInput;
	cout << questionToAsk;
	while (!(cin >> usrInput) || usrInput < lowRange || usrInput > highRange) { //Loop until integer in the specified range is entered
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return usrInput;
}