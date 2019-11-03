/* ******************************************************
 * Name:	Yuren Sun
 * Wisc ID: 9079774791
 * OS:		MacOS Catalina
 * IDE (or text editor): Eclipse
 * Compiler: GCC C++
 * How long did the assignment take you to complete in minutes: 60
 * What other resources did you consult (copy and paste links below): N.A
 *
 */ // ******************************************************
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counter;

// prototypes
void Print_Numbers(vector<int> numbers);
int Get_User_Input();
void Input_Numbers(vector<int> &numbers);
void Safe_Insert(vector<int> &numbers);
void Safe_Delete(vector<int> &numbers);
void Sort_Numbers(vector<int> &numbers);
void Sort_And_Remove_Duplicates(vector<int> &numbers);
int Sum(vector<int> numbers);

/**
 * This function gets a number from the user with cin and returns that number.
 *
 * @return: int, a number entered by the user
 */
int Get_User_Input() {
	int n;
	cin >> n;
	return n;
}

/**
 * This function prints out the number and position in the vector of each element
 *
 * @param: the vector of numbers
 */
void Print_Numbers(vector<int> numbers) {
	// print the header
	cout << "The numbers in the vector are:" << endl;

	// erate through the vector and for each entry,
	// and print the position and value so that it matches the sample output
	for (int i = 0; i < numbers.size(); i++) {
		cout << "The value at position [" << i << "] is " << numbers.at(i)
				<< endl;
	}
}

/**
 * Clear the vector of numbers
 * Request that the user enter a number or -1 to quit
 * Get the number from the user using the Get_User_Input function,
 * and add it to the end of the vector
 * Keep requesting the user enter an integer until they enter a -1
 *
 * @param: numbers, the vector of numbers by reference
 */
void Input_Numbers(vector<int> &numbers) {
	// Clear the vector of numbers
	numbers.clear();

	// quest that the user enter a number or -1 to quit
	cout << "Please enter a number or -1 to quit: ";

	// Get the number from the user using the Get_User_Input function
	int choice = Get_User_Input();

	// Keep requesting the user enter an integer until they enter a -1
	while (choice) {
		switch (choice) {
		case -1:
			return;
		default:
			// add the number to the end of the vector
			numbers.push_back(choice);
			// prompt the user again
			cout << "Please enter a number or -1 to quit: ";
			// get a new number
			choice = Get_User_Input();
		}
	}
}

/**
 * The function first prompts the user to enter the index where they would like to insert the new number
 * Use the function Get_User_Input to read this index
 * The function then prompts the user to indicate the number to be inserted
 * Use the function Get_User_Input to read this number
 * If the given index is negative, insert the integer into position 0
 * If the given index is greater than the size of the vector, insert the integer at the end of the vector
 * Otherwise insert the integer at the index provided by the user
 *
 * @param: numbers, the vector of numbers by reference
 */
void Safe_Insert(vector<int> &numbers) {
	// prompts the user to enter the index where they would like to insert the new number
	cout << "Enter the index where you would like to insert a number: ";
	int pos = Get_User_Input();
	// prompts the user to indicate the number to be inserted
	cout << "Enter the the number to be inserted: ";
	int num = Get_User_Input();

	if (pos < 0) {
		// If the given index is negative, insert the integer into position 0
		numbers.insert(numbers.begin(), num);
	} else if (pos >= numbers.size()) {
		// If the given index is greater than the size of the vector,
		// insert the integer at the end of the vector
		numbers.push_back(num);
	} else {
		// insert the integer at the index provided by the user
		numbers.insert(numbers.begin() + pos, num);
	}
}

/**
 * Prompt the user to enter the index of the number to be deleted
 * Use Get_User_Input to read the index
 * Remove the number at the given index if valid
 * If the given index is negative, remove the integer at index 0
 * If the given index is greater than the size of the vector, remove the last integer in the vector
 * If the vector is empty, make no changes to the vector
 *
 * @param: numbers, the vector of integers by reference
 */
void Safe_Delete(vector<int> &numbers) {
	// Prompt the user to enter the index of the number to be deleted
	cout << "Enter the index where you would like to delete a number: ";
	// Use Get_User_Input to read the index
	int pos = Get_User_Input();

	if (numbers.empty()) {
		// If the vector is empty, make no changes to the vector
		return;
	} else {
		if (pos < 0) {
			// If the given index is negative, remove the integer at index 0
			numbers.erase(numbers.begin());
		} else if (pos >= numbers.size()) {
			// If the given index is greater than the size of the vector,
			// remove the last integer in the vector
			numbers.pop_back();
		} else {
			numbers.erase(numbers.begin() + pos);
		}
	}
}

/**
 * This function sorts the numbers in ascending order
 * using sort in C++ algorithm library
 *
 * @param: numbers, the vector of integers by reference
 */
void Sort_Numbers(vector<int> &numbers) {
	sort(numbers.begin(), numbers.end());
}

/**
 * This function sorts the numbers in ascending order and removes duplicate numbers
 * using unique and sort in algorithm library
 *
 * @param: numbers, the vector of integers by reference
 */
void Sort_And_Remove_Duplicates(vector<int> &numbers) {
	sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
}

/**
 * This function sorts the numbers in ascending order and removes duplicate numbers
 *
 * @param: numbers, the vector of integers
 */
int Sum(vector<int> numbers) {
	int sum = 0;

	// iterate through the vector to compute the sum
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers.at(i);
	}

	return sum;
}

// #### DO ALL OF YOUR WORK ABOVE THIS LINE!!! ###
// #### We will copy and paste everything above into the grading script for testing
int main() {
	counter = 0;
	vector<int> numbers;
	int total = 0;
	int choice = 1;

	cout << "0. Quit" << endl;
	cout << "1. Input_Numbers" << endl;
	cout << "2. Safe_Insert" << endl;
	cout << "3. Safe_Delete" << endl;
	cout << "4. Sort_Numbers" << endl;
	cout << "5. Sort_And_Remove_Duplicates" << endl;
	cout << "6. Sum" << endl;
	cout << "7. Print_Numbers" << endl << endl;

	while (choice) {
		cout << "Choose one of the menu options: ";
		choice = Get_User_Input();

		switch (choice) {
		case 0:
			break;
		case 1:
			Input_Numbers(numbers);
			break;
		case 2:
			Safe_Insert(numbers);
			break;
		case 3:
			Safe_Delete(numbers);
			break;
		case 4:
			Sort_Numbers(numbers);
			break;
		case 5:
			Sort_And_Remove_Duplicates(numbers);
			break;
		case 6:
			total = Sum(numbers);
			cout << "The total is " << total << endl;
			break;
		case 7:
			Print_Numbers(numbers);
			break;
		default:
			break;
		}
		cout << endl;
	}

	return 0;
}
