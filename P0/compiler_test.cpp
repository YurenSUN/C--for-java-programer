#include <iostream>
using namespace std;

int main() {
	long unsigned int student_id_number;
	cout << "Please enter your 10 digit student id number: ";
	cin >> student_id_number;
	int x = abs(int(-student_id_number) % 500) << 1;
	cout << "Your code is: " << x << endl;
	return 0;
}
