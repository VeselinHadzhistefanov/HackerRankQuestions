#include <iostream>
#include <string>
using namespace std;


void printStringInfos(string s1, string s2) {
	cout << s1.length() << " " << s2.length() << endl;
	cout << s1 << s2 << endl;
	cout << s2[0] << s1.substr(1) << " " << s1[0] << s2.substr(1);
}


int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	printStringInfos(s1, s2);
}