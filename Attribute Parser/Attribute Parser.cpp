#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

void parseHRML(vector<string> HRMLLines, vector<string> queries) {

	vector<vector<string>> HRML;

	for (int i = 0; i < HRMLLines.size(); i++) {
		stringstream ss(HRMLLines[i]);

		char ch;
		string element = "";
		string type;

		string tagName;
		vector<string> attributes;
		int numQuotes = 0;

		while (ss >> ch) {
			if (ch == '<') {
				type = "tagName";
			}

			if (ch == ' ') {
				if (type == "tagName") {
					tagName = element;
				}
				type = "attribute";
				element = "";
				continue;
			}

			if (type == "tagName") {
				element.push_back(ch);
			}

			if (type == "attribute") {
				if (ch == '>') {
					continue;
				}

				element.push_back(ch);
				if (ch == '"') {
					numQuotes++;
				}

				if (numQuotes == 2) {
					attributes.push_back(element);
					numQuotes = 0;
					element = "";
				}
			}
		}

		HRML.push_back(attributes);
	}

	vector < vector<vector<string>>> HRMLAttributes;

	for (int i = 0; i < HRML.size(); i++) {
		for (int j = 0; j < HRML[i].size(); j++) {

			string name;
			string value;
			if()



		}
	}

}


int main() {
	int numLinesHRML;
	int numQueries;
	cin >> numLinesHRML >> numQueries;

	vector<string> HRMLLines;

	for (int i = 0; i < numLinesHRML; i++) {
		string HRMLLine;
		string s;
		while (cin >> s) {
			HRMLLine.append(s + " ");
		}

		HRMLLines.push_back(HRMLLine);
	}

	vector<string> queryLines;

	for (int i = 0; i < numQueries; i++) {
		string s;
		cin >> s;
		queryLines.push_back(s);
	}

	parseHRML(HRMLLines, queryLines);

	return 0;
}
