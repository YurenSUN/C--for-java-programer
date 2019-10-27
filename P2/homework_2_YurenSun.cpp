/* ******************************************************
 * Name: Yuren Sun
 * Wisc ID: 9079774791
 * OS: MacOS
 * IDE (or text editor): Eclipse
 * Compiler: GCC C++ Compiler
 * How long did the assignment take you to complete in minutes: 90
 * What other resources did you consult (copy and paste links below): N.A
 */ // ******************************************************
// note the grading script will only allow these include files - do not add extra #includes
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_CLASS_SIZE = 100;
const int MAX_NUMBER_OF_ASSIGNMENTS = 100;

// do not change these prototypes.  Add your code to the function definitions below
void Read_Grade_File(string names[MAX_CLASS_SIZE][2],
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
		int *number_of_students, int *number_of_assignments,
		const string input_filename);
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2],
		const int number_of_students);
void Compute_Total_And_Percent(
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[],
		float percent[], int number_of_students, int number_of_assignments);
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[],
		float percent[], const int number_of_students,
		const string output_filename);

// There is no need to change main. However you are encouraged to write code
// that writes data to the console to check the correctness of each of your functions as
// as you work.
int main() {
	string input_filename = "unformatted_grades_2.txt";
	string output_filename = "formatted_grades_2_test.txt";
	string names[MAX_CLASS_SIZE][2];
	int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS];
	int number_of_students = 0;
	int number_of_assignments = 0;
	int total[MAX_CLASS_SIZE];
	float percent[MAX_CLASS_SIZE];

	Read_Grade_File(names, scores, &number_of_students, &number_of_assignments,
			input_filename);
	Format_Case_Of_Names(names, number_of_students);
	Compute_Total_And_Percent(scores, total, percent, number_of_students,
			number_of_assignments);
	Write_Formatted_Grades(names, total, percent, number_of_students,
			output_filename);
	return 0;
}

/**
 * This function takes the name of the input file and pointers to some data structures
 * that will hold the names and scores for other functions to process
 * and pointers to variables that will keep track of the number of students and assignments.
 *
 * @param names[MAX_CLASS_SIZE][2] is the array containing students' names
 * @param scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS]
 * 		  is the array containing students' scores
 * @param *number_of_students
 * @param *number_of_assignments
 * @param input_filename
 *
 * @return void
 **/
void Read_Grade_File(string names[MAX_CLASS_SIZE][2],
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
		int *number_of_students, int *number_of_assignments,
		const string input_filename) {
	ifstream in;
	in.open(input_filename);
	char str[256];
	char *token = NULL;

	//first line
	in.getline(str, 256);
	token = strtok(str, " ");
	token = strtok(NULL, " ");
	*number_of_students = atoi(token);

	//second line
	in.getline(str, 256);
	token = strtok(str, " ");
	token = strtok(NULL, " ");
	*number_of_assignments = atoi(token);

	//third line
	in.getline(str, 256);

	//fourth line and later
	for (int i = 0; i < *number_of_students; i++) {
		in.getline(str, 256);

		//set students' names
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		names[i][0] = token;
		token = strtok(NULL, " ");
		names[i][1] = token;

		//set students' scores
		token = strtok(NULL, " ");
		for (int j = 0; j < *number_of_assignments; j++) {
			scores[i][j] = atoi(token);
			token = strtok(NULL, " ");
		}
	}
}

/**
 *  This function takes the array of first and last names and
 *  changes the strings so that the first letter of each string
 *  is a capital letter and all other letters are lower case.
 *
 *  @param names[MAX_CLASS_SIZE][2] is the array containing students' names
 *  @param number_of_students
 *
 *  @return void
 */
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2],
		const int number_of_students) {
	for (int i = 0; i < number_of_students; i++) {
		// format the first names
		string curStr = names[i][0];
		transform(curStr.begin(), curStr.begin() + 1, curStr.begin(),
				::toupper);
		transform(curStr.begin() + 1, curStr.end(), curStr.begin() + 1,
				::tolower);
		names[i][0] = curStr;

		// format the last names
		curStr = names[i][1];
		transform(curStr.begin(), curStr.begin() + 1, curStr.begin(),
				::toupper);
		transform(curStr.begin() + 1, curStr.end(), curStr.begin() + 1,
				::tolower);
		names[i][1] = curStr;
	}
}

/**
 * This function takes the score array and computes the total score
 * (the sum of all points earned)
 * and the final percent as a double
 * and stores these computed results in the appropriate arrays.
 *
 * @param scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS]
 * 		  is the array containing students' scores
 * @param total is the array store total scores of every students
 * @param percent is the array store the percent of every students
 * @param number_of_students
 * @param number_of_assignments
 *
 * @return void
 */
void Compute_Total_And_Percent(
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[],
		float percent[], int number_of_students, int number_of_assignments) {
	int sum = 0; // record the total score of each student

	for (int i = 0; i < number_of_students; i++) {
		sum = 0;
		for (int j = 0; j < number_of_assignments; j++) {
			sum += scores[i][j];
		}

		total[i] = sum;
		percent[i] = float(sum * 10) / number_of_assignments;
	}
}

/**
 * This function format the grades and output the grade
 *
 * @paran names[MAX_CLASS_SIZE][2] is the array containing every student's name
 * @param total is the array containing the total scores of every student
 * @param percent is the array containing the percents scores of every student
 * @param number_of_students
 * @param output_filename
 *
 * @return void
 */
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[],
		float percent[], const int number_of_students,
		const string output_filename) {
	ofstream out;
	out.open(output_filename);

	// string recording all the info to output
	string name = "";
	string totalStr = "";
	string percentStr = "";
	char percentChar[256];

	for (int i = 0; i < number_of_students; i++) {
		// convert all the info to string
		name = names[i][1] + ", " + names[i][0];
		totalStr = to_string(total[i]);
		sprintf(percentChar, "%.1f", percent[i]);
		percentStr = percentChar;

		// set spaces and output
		int name_total_space = 24 - name.length() - totalStr.length();
		int total_percent_space = 31 - name.length() - totalStr.length()
				- name_total_space;
		out << name << setw(name_total_space) << totalStr
				<< setw(total_percent_space) << percentStr << "\n";
	}
	out.close();
}

