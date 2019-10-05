/* *******************************************************
 * Name: Yuren Sun
 * Wisc ID: 9079774791
 * OS: MacOS Mojave
 * IDE / text editor: Eclipse for C/C++ programer
 * Compiler: GCC C++ Compiler
 * How long did the assignment take you to complete in minutes: 30mins
 * What other resources did you consult (copy and paste links below: N.A.
*/ // ****************************************************

// Include appropriate libraries to work with input/output and strings.
#include <string>
#include <iostream>


using namespace std;

// function declarations -- do not changes these
// you must complete the function definitions below
string Get_Name();
void Print_Welcome_Message(string name);

// do not change main
int main() {
	string name;
	name = Get_Name();
	Print_Welcome_Message(name);
}


// Get_Name asks the user to enter their name
// Note: "Blackbeard", "Anne Bonny", and
// "Captain Jack Sparrow" are all valid names
// The user may also choose not to enter a name.
// input: none
// output: a string containing the user entered name
// Note: do not change the function prototype on the next line
string Get_Name() {
	// declare a variable to hold the name
	string name = "Mike";

	// prompt the user to enter a name
	cout << "Enter your name: ";

	// read the name entered by the user
	getline (std::cin,name);

	// return the name entered by the user
	return name;
}

// Prints the welcome message
// input: a string with the user's name
// output: writes the welcome message to the screen
// return value: none
void Print_Welcome_Message(string name) {
 	// construct all the lines
	string msg;
	if (name.length() > 0)
		msg = " Hello " + name + "! Welcome to CS 368 (C++)! ";
	else
		msg = " Hello! Welcome to CS 368 (C++)! ";
	string stars = "*";
	string blanks = "*";

	//fill the messages
	for(int i=1; i<=msg.length(); i++){
		stars += "*";
		blanks += " ";
	}

	stars += "*";
	blanks += "*";

    // print the top row of stars
	cout << "\n" + stars << endl;

	// print the second line
	cout << blanks <<endl;

	// print the welcome message
	cout<< "*" + msg + "*" <<endl;

	// print the fourth line
	cout << blanks << endl;

	// print the bottom row of stars
	cout << stars << endl;

	return;
}
