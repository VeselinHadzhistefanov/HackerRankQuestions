#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {

	char ch;
	vector<int> integers;

	stringstream ss(str);

	bool continueParse = true;
	while (continueParse) {
		int a;
		if (ss >> a) {
			integers.push_back(a);
			if (!(ss >> ch)) {
				continueParse = false;
			}
		}
	}

	return integers;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}