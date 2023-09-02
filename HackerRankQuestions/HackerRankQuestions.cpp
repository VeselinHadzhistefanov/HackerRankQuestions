#include <iostream>
using namespace std;

string NUM_TEXT[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void printNumText(int n) {

	if (n < 1) {
	}
	else if (n >= 1 && n <= 9) {
		cout << NUM_TEXT[n - 1];
	}
	else {
		cout << "Greater than 9";
	}

}



int main() {
	int n;
	cin >> n;

	printNumText(n);
}