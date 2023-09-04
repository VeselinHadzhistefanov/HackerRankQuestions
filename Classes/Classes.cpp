#include <iostream>
#include <sstream>
using namespace std;

class Student {
private:
	int age;
	string first_name;
	string last_name;
	int standard;

public:

	int get_age() {
		return this->age;
	}

	void set_age(int age) {
		this->age = age;
	}

	string get_first_name() {
		return first_name;
	}

	void set_first_name(string first_name) {
		if (first_name.length() > 50)
			return;
		this->first_name = first_name;
	}

	string get_last_name() {
		return last_name;
	}

	void set_last_name(string last_name) {
		if (last_name.length() > 50)
			return;
		this->last_name = last_name;
	}

	int get_standard() {
		return this->standard;
	}

	void set_standard(int standard) {
		this->standard = standard;
	}

	string to_string() {
		string s;
		s += std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);

		return s;
	}
};


int main() {
	std::cout << "Hello World!\n";
}