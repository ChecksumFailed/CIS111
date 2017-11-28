//Ben Scherer
// 6/17/2017
// Mid Term Project -  Overseas Credit Card Cost Calculator
// Determines the total cost of an item in USD for credit card purchases made overseas

#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <utility>  //needed for pair
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits

using namespace std;

//Functions
int getCurrencyType();
double getPurchasePrice();
void currencyChoiceMenu();
pair<string,double> getCurrencyData(int currencyType); //returns currency name and exchange rate

int main() {
				
	//Constants
	const double feeRate = 0.03;

	//input Variables
	double purchasePrice; //Purchase price prior to conversion to USD
	int currencyChoice; //used in choice menu selection for foreign currency type

	//Output Variables
	double totalFees; //Total calculated fees of purchase
	double totalFeesUSD; //Total calculated fees of purchase in USD
	double purchasePriceUSD; //Currency converted to USD
	double totalCost; // purchaseprice + fees
	double totalCostUSD; // purchaseprice + fees(USD)
	double exchangeRate; //Exchange rate used to convert currency to USD
	double conversionFee = 0.03; //Combined fees charged by CC company and banks
	double totalCostDiff; //Price difference once fees and exchange rate are calulated
	string currencyName; //Friendly name of currency
	pair<string, double> currencyData; //contains currency name and exchange rate

	//get input
	purchasePrice = getPurchasePrice();
	currencyChoice = getCurrencyType();

	//Get currency name and exchange rate
	currencyData = getCurrencyData(currencyChoice);
	currencyName = currencyData.first;
	exchangeRate = currencyData.second;

	//Cost and fees prior to conversion
	totalFees = purchasePrice * feeRate;
	totalCost = totalFees + purchasePrice;

	//Price,cost and fees after conversion
	purchasePriceUSD = purchasePrice * exchangeRate;
	totalFeesUSD = totalFees * exchangeRate;
	totalCostUSD = purchasePriceUSD + totalFeesUSD;
	totalCostDiff = totalCostUSD - purchasePrice;

	//output
	cout << "-------------------------------------------------------------------------------\n"
		<< "Purchase cost in US Dollars(USD)\n"
		<< "-------------------------------------------------------------------------------\n"
		<< "\t" << setw(30) << left << "Currency Type: " << currencyName << endl
		<< "\t" << setw(30) << left << "Conversion Fee Rate: " << (feeRate * 100) << "%" << endl
		<< "\t" << setw(30) << left << "Currency Exchange Rate: " << exchangeRate  << endl
		<< "-------------------------------------------------------------------------------\n"
		<< "Cost before USD Conversion:\n"
		<< "\t" << setw(30) << left << "Original Purchase Price: " << setprecision(2) << fixed << purchasePrice << endl
		<< "\t" << setw(30) << left << "Total Fees: " << setprecision(2) << fixed << totalFees << endl
		<< "\t" << setw(30) << left << "Total Cost: " << setprecision(2) << fixed << totalCost << endl
		<< "\nCost after USD Conversion:\n"
		<< "\t" << setw(30) << left << "Purchase Price(USD): " << setprecision(2) << fixed << purchasePriceUSD << endl
		<< "\t" << setw(30) << left << "Total Fees(USD): " << setprecision(2) <<fixed << totalFeesUSD << endl
		<< "\t" << setw(30) << left << "Total Cost(USD): " << setprecision(2) << fixed << totalCostUSD << endl
		;

	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(); 
	return 0;
}

//Prompts user for currency type and does input validation
int getCurrencyType() {
	int currencyType;
	bool isValidInput = false;
	currencyChoiceMenu();
	while (!isValidInput) {
		
		if (!(cin >> currencyType) || (currencyType < 1 || currencyType > 8)) {

			cout << "#####################################################\n";
			cout << "\tERROR: ENTER A NUMBER BETWEEN 1-8\n";
			cout << "#####################################################\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	}
	return currencyType;

}

//Prompts user for purchase price and does input validation
double getPurchasePrice() {
	double purchasePrice;
	bool isValidInput = false;
	
	while (!isValidInput) {
		cout << "\nEnter purchase price\n";
		if (!(cin >> purchasePrice)) {

			cout << "#####################################################\n";
			cout << "\tERROR: PURCHASE PRICE MUST BE A VALID NUMBER\n";
			cout << "#####################################################\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	}
	return purchasePrice;
}

//Generates choice menu for currency type
void currencyChoiceMenu() {
	cout <<  "\n-------------------------\n"
			 "Currency Type:\n" 
	       	"-----------------------------\n"
			"1. Euro\n"
			"2. British Pound\n"
			"3. Indian Rupee\n"
			"4. Mexican Peso\n"
			"5. Canadian Dollar\n"
			"6. Australian Dollar\n"
			"7. Japanese Yen\n"
			"8. Chinese Yan Renminibi\n"
			"-----------------------------\n"
			"Enter type of currency (1-8):\n";
}

//Returns Currency Name and exchange rate based on choice
pair<string, double> getCurrencyData(int currencyType) {
	
	switch (currencyType) {
		case 1: return make_pair("Euro", 1.118863);
		case 2: return make_pair("British Pound", 1.277844);
		case 3: return make_pair("Indian Rupee", 0.015516);
		case 4: return make_pair("Mexican Peso", 0.055826);
		case 5: return make_pair("Canadian Dollar", 0.756819);
		case 6: return make_pair("Australian Dollar", 0.756819);
		case 7: return make_pair("Japanese Yen", 0.009027);
		case 8: return make_pair("Chinese Yuan Renminbi", 0.146835);
		
	}

	
}