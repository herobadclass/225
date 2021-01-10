#include <iostream>
#include <math.h>
using namespace std;

int main (void) {
	float input;
	cin >> input;
	if( fmod(input,2) == 0) {
		cout << "Even";
	}
	else if( fmod(input,2) == 1) {
		cout << "Odd";
	}
	else {
		cout << "Nonint";
	}
	return 0;
}