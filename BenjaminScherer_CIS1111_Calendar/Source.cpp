#include <iostream>
#include <iomanip>
#include <string> //needed for string variable
#include <limits> //user for numeric_limits

using namespace std;
//functions
char getSentinel(); //Input validation for sentinel.  simple y/n
char getSentinel(); //Input validation for sentinel.  simple y/n
int searchArr(const string searchArr[], int arrSize, string searchString);
string getInput(string questionToAsk, string errorMsg);
int getInput(string questionToAsk, string errorMsg, int year);
int getMonth(string months[]);
int getDay(string months[]);
void displayCalendar(string month, int year, int numDays, int day);


int main() {
	//variables
	string months[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	string daysOfWeek[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
	int daysPerMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	//index of string
	int monthIndex, day, year,numDays;

	do {
		monthIndex = getMonth(months);
		year = getInput("Enter year for " + months[monthIndex] + ": " , "Error: Enter valid year",1);
		day = getDay(daysOfWeek);
		numDays = daysPerMonth[monthIndex];
		if (year % 4 == 0 && monthIndex == 1)
			numDays++;

		displayCalendar(months[monthIndex], year, numDays,day);
		
		
	} while (getSentinel() == 'y');
	
	
}


void displayCalendar(string monthName, int year,int numDays,int day) {
	int month[5][7] = { {0} };
	int counter=0;
	//Fill out week one with offset
	for (int i = day; i < 7; i++) {
		counter++;
		month[0][i] = counter;
	}
	//Populate the rest of the days
	for (int i = 1; i < 5; i++) {
		for (int x = 0; x < 7; x++) {
			counter++;
			if (counter <= numDays )
				month[i][x] = counter;
		}

	}

	//Print the Calendar
	cout <<  monthName << "\t" << year << endl;
	cout << "S  " << "M  " << "T  " << "W  " << "T  " << "F  " << "S  \n";
	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 7; x++) {
			if (month[i][x] == 0) //Ignore 0 values
				cout << "   ";
			else
				cout << setw(3) <<  left << month[i][x];
		}
		cout << endl;
	}


	
}

//Validates user input for month. Returns int index
int getMonth(string months[]) {
	int month;
	do {
		month = searchArr(months, 12, getInput("Enter name of month: ", "Error: Enter a valid month"));
	} while (month == -1);
	return month;

}

//Validates input for day.  returns  int index
int getDay(string days[]) {
	int month;
	do {
		month = searchArr(days, 12, getInput("Enter name of day this month starts on: ", "Error: Enter a valid day"));
	} while (month == -1);
	return month;

}

//Search String array and return position
int searchArr(const string searchArr[],int arrSize, string searchString) {
	for (int i = 0; i < arrSize; i++) {
		if (searchArr[i] == searchString)
			return i;
	}
	return -1;
}


//Validates input, returns string
int getInput(string questionToAsk, string errorMsg, int intVar) {
	int usrInput;
	cout << questionToAsk;
	while (!(cin >> usrInput)) { //Loop until integer in the specified range is entered
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return usrInput;
}

//Validates input, returns string
string getInput(string questionToAsk, string errorMsg) {
	string usrInput;
	cout << questionToAsk;
	while (!(cin >> usrInput)) { //Loop until integer in the specified range is entered
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return usrInput;
}

//validates sentinel input, then returns char value
char getSentinel() {
	char  varToReturn;
	bool isValidInput = false;

	// loop until a valid y or n char is entered
	do {
		cout << "\nEnter 'y' to enter more data.  Enter 'n' if you are finished: ";
		if (!(cin >> varToReturn) || (tolower(varToReturn) != 'y' && tolower(varToReturn) != 'n')) {
			cout << "\tERROR: Enter 'y' to  enter more data.  Enter 'n' if you are finished";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	} while (!isValidInput);

	return tolower(varToReturn);
}