#include "bruteForce.h"
#include <iostream>
#include <chrono> //time library

using namespace std;
using namespace std::chrono;

string getUserInput() {

	string password;
	cout << "Enter password to crack: ";
	cin >> password; 
	return password;
}

bool bruteForce(string current, const string& target, int maxLength) {
	if (current == target) {
		return true; //password found
	}

	if (current.length() >= maxLength) {
		return false; //stop when max length is reached
	}

	for (size_t i = 0; i < CHARSET.size(); i++) {
		if (bruteForce(current + CHARSET[i], target, maxLength)) {
			return true;
		}
	}

	return false;
}

void startBruteForce(const string& password) {

	auto start = high_resolution_clock::now(); //start timer

	for (int length = 1; length <= password.length(); length++) {
		if (bruteForce("", password, length)) {
			auto stop = high_resolution_clock::now(); //stop timer
			auto duration = duration_cast<milliseconds>(stop - start);

			cout << "Password: " << password << endl;
			cout << "Time taken: " << duration.count() / 1000.0 << "Seconds" << endl;
			return;
		}
	}

	cout << "Password not found within reasonable limits!" << endl;
}