//Ben Scherer
// 7/15/2017
// SkiersCompetition
//  Menu based program to display/calculate information about ski competition results.  Leverages parallel arrays

//Headers to include
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits


using namespace std;

//Global variables
const int SIZE = 5; //Size of parallel arrays

//function prototypes/overrides
void displaySkiers(string skierNames[]); //Displays all names in skier array
void displayResults(string skierNames[], double skiTimes[]); //Displays all results from competition
void displayChoiceMenu();  //Choice menu for program
void displayFastest(string names[], double times[]);
void displayAverageTime(double skiTimes[]);
string getStrInput(string msgToDisplay); //Input validation of strings
int getIntInput(); //Input Validation of Int
void displaySkiers(string skierNames[]); //Displays all names in skier array
void getSkier(string skierNames[], double skiTimes[]);  //Prompt user for skier name and search array
int searchStrArray(string strArray[], string strToSearch, int arrSize);//search array for string


int main() {
	string skierNames[] = { "Leela","Sarah","Anna","Keesha","Heidi" };
	double skiTimes[] = { 2.03,2.40,1.85,1.90,2.50 };
	int choice;

	do {
		displayChoiceMenu();
		choice = getIntInput();
		switch (choice) {
			case 1: displayFastest(skierNames, skiTimes);
					break; 
			case 2: displayAverageTime( skiTimes);
					break;
			case 3: getSkier(skierNames, skiTimes);
					break;
			case 4: displayResults(skierNames, skiTimes);
					break;
		}
			
			
	} while (choice >= 1 && choice <= 4);

}

void displayChoiceMenu() {
	cout << "--------------------------------------------------------------\n"
		<< "Super elite ski compeition 2017 \n"
		<< "--------------------------------------------------------------\n"
		<< "1 - Fastest skier in competition \n"
		<< "2 - Average time of field \n"
		<< "3 - Search results \n"
		<< "4 - Display all results\n"
		<< "Please enter a number between 1-4. Select any other number to exit program\n"
		;

}

void displayResults(string skierNames[], double skiTimes[]) {
	cout << "Ski Competition Results:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << skierNames[i] << "\t" << skiTimes[i] << endl;
	}
}

//Displays all names in skier array
void displaySkiers(string skierNames[]) {
	cout << "Skiers:\n";
	for (int i = 0;i < SIZE;i++)
		cout << "\t" << skierNames[i] << endl;
}



//Prompt user for skier name and search array
void getSkier(string skierNames[], double skiTimes[]) {
	int skierIndex;
	displaySkiers(skierNames);
	string strSkier;

	do {
		
		strSkier = getStrInput("Enter names of skier\n");
		skierIndex = searchStrArray(skierNames,strSkier , SIZE);
		if (skierIndex == -1)
			cout << "ERROR: Skier not found. Please try again\n";
	} while (skierIndex == -1);
		
		cout << skierNames[skierIndex] << "'s time is " << skiTimes[skierIndex] << endl;

}

//Search Array for string
int searchStrArray(string strArray[],string strToSearch, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		/*cout << strArray[i] << endl;
		cout << strToSearch << endl;
		cout << strcmp(strArray[i].c_str(), strToSearch.c_str()) << endl;
		*/
	//	if (strcmp(strArray[i].c_str(),strToSearch.c_str()) == 0) {
		if (strArray[i] == strToSearch) {
			return(i);
		}
	}
	return -1;

}


//Finds Fastest skier and displays results
void displayFastest(string names[], double times[]) {
	double highScore = 0.0;
	int scoreIndex;
	
		for (int i = 0; i < SIZE;i++) {
			if (times[i] > highScore) {
				highScore = times[i];
				scoreIndex = i;
			}
	}
	cout << "The fastest skier is " << names[scoreIndex] << " with a time of " << times[scoreIndex] << "!!!\n";
	
}

//Calculate average time and display results
void displayAverageTime(double skiTimes[]) {
	double sumTime = 0.0;
	for (int i = 0; i < SIZE;i++) {
		sumTime += skiTimes[i];
	}
	cout << "The average time is " << (sumTime / SIZE) << endl;

}

//Validates int input
int getIntInput() {
	int usrInput;
	
	while (!(cin >> usrInput)) { //Loop until integer in the specified range is entered
		cout << "ERROR: Enter a valid number\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return int(usrInput);
}


//Validates string input
string getStrInput(string msgToDisplay) {
	string usrInput;
	cout << msgToDisplay;
	while (!(cin >> usrInput)) { //Loop until integer in the specified range is entered
		cout << "ERROR: Enter a valid string\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return usrInput;
}