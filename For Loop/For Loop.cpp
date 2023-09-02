#include <iostream>
using namespace std;

string NUM_TEXT[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void printNums(int a, int b) {

	if (a > b) {
		return;
	}

	for (int i = a; i <= b; i++) {
		if (i >= 1 && i <= 9) {
			cout << NUM_TEXT[i - 1] << endl;
		}
		else {
			if (i % 2 == 0) {
				cout << "even" << endl;
			}
			else {
				cout << "odd" << endl;
			}
		}
	}

}

int main() {

	int a, b;
	cin >> a >> b;
	printNums(a, b);
}