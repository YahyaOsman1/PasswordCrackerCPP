#pragma once 
#include <string>

using namespace std;

const string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


//Getting password input from user
string getUserInput();

//Function to perform brute force password crack
bool bruteForce(string current, const string& target, int maxLength);

//Function to start brute force password attack
void startBruteForce(const string& password);
