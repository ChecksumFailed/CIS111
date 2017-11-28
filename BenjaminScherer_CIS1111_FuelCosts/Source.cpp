//Ben Scherer
// 6/22/2017
// Fuel Costs Calculator
//  Based on user input, calculates average gas mileage ,average gas prices and car efficiency class

//Headers to include
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits

using namespace std;

//Functions
double getDoubleInput(string questionToAsk); //Gets and validates input for all double variables
char getSentinel(); //Gets and validates sentinel for breaking loop.  y/n in this case

int main() {
	//Input Variables
	double odometerStart, odometerEnd; //Used to calculate miles traveled between fillups
	double pricePerGallon; //Price paid at fillup
	double numGallons; //Number of gallons purchased
	

	//Output Variables
	double avgMPG; //Average MPG calculated from user inputs
	double avgPricePerGallon; //Average price per gallon based off ot the three gas station prices inputed
	double costPerMile; //Average cost per mile;
	string carClassification; // Car Efficiency classification, based off of avgMPG

	//Misc Variables
	int numFillUps = 0;// counter.  Keeps track of the number of times gas is purchased
	double totalGallons = 0.0; //Total gallons of gas purchased
	double totalMiles = 0.0; //Total miles traveled
	double totalPricePerGallon = 0.0; // sum of price per gallon.  Used to calculate average
	double totalCost; //Total money spent on gas

	//Get user input
	cout << "---------------------------------------------------------\n";
	cout << "\t\tCIS 1111 Fuel Cost Calculator\n";
	cout << "---------------------------------------------------------\n";
	cout << "Please enter readings:\n ";
	do { //Get odometer readings and gallons purchased
		odometerStart = getDoubleInput("Initial Odometer reading(miles): ");
		odometerEnd = getDoubleInput("Ending Odometer reading(miles): ");
		numGallons = getDoubleInput("Gallons of gas purchased: ");
		
		numFillUps++;
		totalMiles += (odometerEnd - odometerStart);
		totalGallons += numGallons;

	} while (getSentinel() == 'y');

	//Get gas prices
	for (int i = 1; i <= 3; i++) {
		pricePerGallon = getDoubleInput("Please enter price per gallon at gas station #" + to_string(i));
		totalPricePerGallon += pricePerGallon;
	}

	//Calculate Averages
	avgMPG = totalMiles / totalGallons;
	avgPricePerGallon = totalPricePerGallon / 3;
	totalCost = (totalGallons * avgPricePerGallon);
	costPerMile = totalMiles / totalCost;
	
	if (avgMPG <= 15)
		carClassification = "Very Inefficient";
	else if (avgMPG >= 16 && avgMPG <= 30)
		carClassification = "OK";
	else
		carClassification = "Very Efficient";

	//output
	cout << "\n---------------------------------------------------------------\n"
		<< "Caclulated Fuel Costs\n"
		<< "---------------------------------------------------------------\n"
		<< setw(40) << left << "Number of trips to gas station: " << numFillUps << endl
		<< setw(40) << left << "Total Miles Driven: " << totalMiles << endl
		<< setw(40) << left << "Average Miles Per Gallon(MPG): " << setprecision(2) << fixed << avgMPG << endl
		<< setw(40) << left << "Average fuel cost per gallon: " << "$" << avgPricePerGallon << endl
		<< setw(40) << left << "Total spend on fuel: " << "$" <<  setprecision(2) << fixed << totalCost << endl
		<< setw(40) << left << "Cost per mile: " << "$" << setprecision(2) << fixed << costPerMile << endl
		<< setw(40) << left << "Car Efficiency Rating: " << carClassification << endl
		;

	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}

double getDoubleInput(string questionToAsk) {
	double varToReturn;
	bool isValidInput = false;

	do {
		cout << questionToAsk << endl;
		if (!(cin >> varToReturn)) {

			cout << "#####################################################\n";
			cout << "\tERROR: Please enter a valid value\n";
			cout << "#####################################################\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	} while (!isValidInput);
	return varToReturn;
}

char getSentinel() {
	char  varToReturn;
	bool isValidInput = false;

	do {
		cout << "Enter 'y' to enter more readings.  Enter 'n' if you are finished" << endl;
		if (!(cin >> varToReturn) || (tolower(varToReturn) != 'y' && tolower(varToReturn) != 'n')) {

			cout << "#####################################################\n";
			cout << "\tERROR: Enter 'y' to enter more readings.  Enter 'n' if you are finished\n";
			cout << "#####################################################\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	} while (!isValidInput);
	return tolower(varToReturn);
}