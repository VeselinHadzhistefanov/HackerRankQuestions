#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int numArrays;
	cin >> numArrays;

	int numQueries;
	cin >> numQueries;

	int** arr = new int* [numArrays];
	for (int i = 0; i < numArrays; i++) {
		int numElements;
		cin >> numElements;

		arr[i] = new int[numElements];

		for (int j = 0; j < numElements; j++) {
			cin >> arr[i][j];
		}
	}

	int* arrNum = new int[numQueries];
	int* arrIdx = new int[numQueries];
	for (int i = 0; i < numQueries; i++) {
		cin >> arrNum[i] >> arrIdx[i];
	}

	for (int i = 0; i < numQueries; i++) {
		cout << arr[arrNum[i]][arrIdx[i]] << endl;
	}

	return 0;
}