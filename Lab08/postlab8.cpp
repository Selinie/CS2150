#include <iostream>
using namespace std;
 
// create a simple function that takes in an object
int passbyValue(int num1, int num2, int num3) {
	return (num1 * num2 * num3);
}

int passbyReference(int& num1, int& num2, int& num3) {
	return (num1 * num2 * num3);
}

int main(){
	cout << "Pass by value: " << passbyValue(5, 1, 2) << endl;

	int num1 = 5;
	int num2 = 1;
	int num3 = 2;

	cout << "Pass by reference: " << passbyReference(num1, num2, num3) << endl;

	return 0;
}