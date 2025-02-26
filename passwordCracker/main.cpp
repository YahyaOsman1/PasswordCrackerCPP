#include "bruteForce.h"
#include <iostream>

using namespace std;

int main() {
	string password = getUserInput();
	cout << "Starting bruteForece crack...." << endl;
	startBruteForce(password);
	return 0;
}