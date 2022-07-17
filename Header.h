#pragma once

#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>

#include"GapInPrimes.cpp"	//Includes func that returns the first pair of two prime numbers spaced with a gap of g between the limits m, n. And isPrime check.

using namespace std;


int romanToNumeric(string roman);		//Function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer

int beeramid(int bonus, double price); //A beer can pyramid will square the number of cans in each level - 1 can in the top level, 4 in the second, 9 in the next, 16, 25...Function to returns the number of complete levels of a beer can pyramid you can make

string format_duration(int seconds); //Function which formats a duration, given as a number of seconds, in a human - friendly way