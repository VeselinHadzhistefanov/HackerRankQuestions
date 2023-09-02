#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

void parseHRML(vector<string> HRMLLines, vector<string> queries) {

	vector<vector<string>> HRML;
	vector<string> tags;


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
		tags.push_back(tagName);
	}

	vector<vector<vector<string>>> HRMLAttributes;

	for (int i = 0; i < HRML.size(); i++) {

		vector<vector<string>> attributes;
		HRMLAttributes.push_back(attributes);

		for (int j = 0; j < HRML[i].size(); j++) {
			stringstream ss(HRML[i][j]);

			char ch;
			string element = "";
			string type = "name";

			string name;
			string value;
			int numQuotes = 0;

			vector<string> attribute;

			while (ss >> ch) {
				if (type == "name") {
					if (ch != ' ') {
						element.push_back(ch);
					}
					else {
						type = "value";
						element = "";
						continue;
					}
				}
				if (ch == '"') {
					if (numQuotes == 0) {
						numQuotes = 1;
					}
					if (numQuotes == 1) {
						value = element;
						continue;
					}
				}

				if (numQuotes == 1 && type == "value") {
					element.push_back(ch);
				}
			}

			attribute.push_back(name);
			attribute.push_back(value);
			HRMLAttributes[i].push_back(attribute);
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
