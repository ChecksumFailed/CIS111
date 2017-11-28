//Ben Scherer
// 7/7/2017
// Sinclair's got talent
// Judges enter scores for multiple contestant.  Low/High score for each contestant dropped and average calculated.   Highest average is declared winner.

//Headers to include
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits
#include <utility> //needed for pair

using namespace std;

//global var
bool debug = false; //set to true to display debug output

//Functions Prototypes/Overrides
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange); //validates int input and int range
string getInput(string questionToAsk, string errorMsg); //validates string input
double calcAvgScore(int score1, int score2, int score3, int score4, int score5); //calculates avg score
int findLowest(int score1, int score2, int score3, int score4, int score5); //finds lowest int from 5 var
int findHighest(int score1, int score2, int score3, int score4, int score5); //finds highest int from 5 var
char getSentinel(); //Input validation for sentinel.  simple y/n
pair<string, double> getScores();
bool checkInt(double num); //checks if number is a whole number


int main() {

	pair<string, double>winner = getScores();//Get scores and find winner
	cout << "\nThe winner of Sinclair's Got Talent! with an average score of " << setprecision(2) << fixed << winner.second << " is ........" << winner.first << "!!!!!\n";

	return(0);
}

//Gets scores from judges. Returns Winner name and score
pair<string, double> getScores() {
	int score1, score2, score3, score4, score5; //5 judge scores
	string contestant;//name of contestant
	double avgScore; //Avg score after droppign lowest and highest score
	pair<string, double> winner; //placeholder for contestant and avgScore 

	do {
		//Get judge scores
		contestant = getInput("Enter name of contestant: ", "ERROR:Enter a valid string");
		score1 = getInput("Enter score 1(1-10): ", "Enter a valid number between 1 - 10", 1, 10);
		score2 = getInput("Enter score 2(1-10): ", "Enter a valid number between 1 - 10", 1, 10);
		score3 = getInput("Enter score 3(1-10): ", "Enter a valid number between 1 - 10", 1, 10);
		score4 = getInput("Enter score 4(1-10): ", "Enter a valid number between 1 - 10", 1, 10);
		score5 = getInput("Enter score 5(1-10): ", "Enter a valid number between 1 - 10", 1, 10);
		
		avgScore = calcAvgScore(score1, score2, score3, score4, score5);//Calculate Avg Score
		
		///Debug Output
		if (debug) cout << "AvgScore: " << avgScore << endl;
		
		if (avgScore > winner.second) //Determine if current contestant is the winner
			winner = make_pair(contestant, avgScore);
	} while (getSentinel() == 'y');

	return winner;
}

//Validates input based on a range.  returns int
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange) {
	double usrInput;
	cout << questionToAsk;
	while (!(cin >> usrInput) || usrInput < lowRange || usrInput > highRange || !(checkInt(usrInput))) { //Loop until integer in the specified range is entered
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return int(usrInput);
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

//Averages 5 scores, dropping lowest and highest
double calcAvgScore(int score1, int score2, int score3, int score4, int score5) {
	int lowScore = findLowest(score1, score2, score3, score4, score5);
	int highScore = findHighest(score1, score2, score3, score4, score5);

	//Debug Output
	if (debug)cout << "LowScore: " << lowScore << "\n";
	if (debug) cout << "HighScore: " << highScore << "\n";

	return (score1 + score2 + score3 + score4 + score5 - lowScore - highScore) / 3.0; //average score
}

//Finds smallest int from 5 variables
int findLowest(int score1, int score2, int score3, int score4, int score5) {
	int lowScore = score1;
	if (score2 < lowScore)
		lowScore = score2;
	if (score3 < lowScore)
		lowScore = score3;
	if (score4 < lowScore)
		lowScore = score4;
	if (score5 < lowScore)
		lowScore = score5;

	return lowScore;
}

//Finds highest int from 5 variables
int findHighest(int score1, int score2, int score3, int score4, int score5) {
	int highScore = score1;
	if (score2 > highScore)
		highScore = score2;
	if (score3 > highScore)
		highScore = score3;
	if (score4 > highScore)
		highScore = score4;
	if (score5 > highScore)
		highScore = score5;

	return highScore;
}

//validates sentinel input, then returns char value
char getSentinel() {
	char  varToReturn;
	bool isValidInput = false;

	// loop until a valid y or n char is entered
	do {
		cout << "\nEnter 'y' to add more contestants.  Enter 'n' if you are finished: " ;
		if (!(cin >> varToReturn) || (tolower(varToReturn) != 'y' && tolower(varToReturn) != 'n')) {
			cout << "\tERROR: Enter 'y' to add more contestants.  Enter 'n' if you are finished\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	} while (!isValidInput);

	return tolower(varToReturn);
}


//checks if double is a whole number.
bool checkInt(double num) {
	if (floor(num) == num)
		return true;
	else
		return false;

}