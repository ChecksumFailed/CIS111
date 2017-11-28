//Ben Scherer
// 6/22/2017
// Averaging Quiz Scores
//  Writes scores for individual students to file, then reads in file to calculate average score

//Headers to include
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <limits> //user for numeric_limits
#include <fstream>//used for file access

using namespace std;

//Functions
void pauseProgram();  //Pauses program until user hits enter key
bool populateQuizData(string fileName,int numQuiz); //Gets user input and writes to file. Returns bool
int getInput(string questionToAsk, string errorMsg); //Basic input validation, returns int
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange); //Input validation for int that must fall within a numeric range.  Returns int
double calculateClassAverage(int numQuiz, string fileName); //Reads data from file and calculates average score.  Returns double
char getSentinel(); //Input validation for sentinel.  simple y/n


//Main function of program
int main() {
	//Variables
	string fileName; //Filename to be used for output/input
	int numQuiz; //Number of scores to input
	double classAvg; //Average of all socres
	
	//Request file name to use
	cout << "Please enter file name to use:";
	cin >> fileName; 

	//Request number of quizes to input for each student
	numQuiz = getInput("Numer of scores to enter per student", "ERROR: Please Enter a valid number");//Get user input and generate quiz results file
	
	if (!populateQuizData(fileName, numQuiz)) { return 1; } // if unable to open file for write, exit program
	
	//Calculate average and output results
	cout << "Calculating average score for class.....\n";
	classAvg = calculateClassAverage(numQuiz, fileName); //Calculate average
	cout << "Average Score for class: " << setprecision(2) << fixed << classAvg  << endl; //Output, 2 decimal 

	pauseProgram(); //Pause program so that results can be viewed
	return 0;
}

//Simple funciton.  Pauses program execution and waits for input
void pauseProgram() {
	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}


// Populates file with quiz data from userInput
bool populateQuizData(string fileName,int numQuiz) {
	ofstream outFile(fileName);
	if (!outFile) {
		cout << "ERROR: Unable to open file for write\n";
		return false;
	}

	//User input loop.  Loops until sentinel is reached.  inner for loop used for score input
	do {
		outFile << getInput("Enter Student ID number: ","ERROR: Please Enter a valid student id");
		for (int i = 1; i <= numQuiz; i++) {
			outFile << "\t" << getInput("Enter score for quiz #" + to_string(i) + ": ", "ERROR: Please enter a valid score",0,100);
		}
		outFile << endl;
	} while (getSentinel() == 'y');
	
	outFile.close();
	return true;
}

//simple input validation.  returns int
int getInput(string questionToAsk,string errorMsg) {
	int score;
	cout << questionToAsk ;
	while (!(cin >> score)) {
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return score;
}

//Validates input based on a range.  returns int
int getInput(string questionToAsk, string errorMsg, int lowRange, int highRange) {
	int score;
	cout << questionToAsk ;
	while (!(cin >> score) || score < lowRange || score > highRange) { //Loop until integer in the specified range is entered
		cout << errorMsg << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return score;
}


//validates sentinel input, then returns char value
char getSentinel() {
	char  varToReturn;
	bool isValidInput = false;

	// loop until a valid y or n char is entered
	do {
		cout << "Enter 'y' to add more student scores.  Enter 'n' if you are finished" << endl;
		if (!(cin >> varToReturn) || (tolower(varToReturn) != 'y' && tolower(varToReturn) != 'n')) {
			cout << "\tERROR: Enter 'y' to add more student scores.  Enter 'n' if you are finished\n";
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			isValidInput = true;
		}
	} while (!isValidInput);

	return tolower(varToReturn);
}

//Calculate class average from scores file, then return double value
double calculateClassAverage(int numQuiz, string fileName) {
	//Attempt to open file for read. Throw error and exit program if open fails
	ifstream inFile(fileName);
	if (!inFile) {
		cout << "ERROR: Unable to open file for write\n";
		exit(1);
	}
	
	int classTotal = 0; //Sum of all quiz scores
	int score; // temporary place holder for scores as read from file
	int studentid; //student id field, used for loop
	int quizCounter = 0; //Total number of scores read from file
	
	//Read test data.  Assumes first field is student id, then <numQuiz> scores
	while (inFile >> studentid) { //Loop until end of file
		
		for (int i = 1; i <= numQuiz; i++) {//read in test scores for student and sum
			inFile >> score;
			classTotal += score;
			quizCounter++;
		}
	
	}
	return (double(classTotal) / quizCounter); //Return average of all quiz scores
}

