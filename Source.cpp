#include "Header.h"

using namespace std;


int main() {
    pair<long long, long long> a = GapInPrimes::gap(10, 300, 400);
    cout << "\n" << a.first << " " << a.second;
    return 0;
}


//Function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer
int romanToNumeric(string roman) {
    map<string, int> alphabet;
    alphabet["I"] = 1;
    alphabet["V"] = 5;
    alphabet["X"] = 10;
    alphabet["L"] = 50;
    alphabet["C"] = 100;
    alphabet["D"] = 500;
    alphabet["M"] = 1000;
    int n = 0;
    for (int i = 0; i < roman.length(); i++) {
        if (i + 1 != roman.length()) {
            while (alphabet[roman.substr(i, 1)] < alphabet[roman.substr(i + 1, 1)]) {
                n -= alphabet[roman.substr(i, 1)];
                i++;
            }
        }
        n += alphabet[roman.substr(i, 1)];
    }
    return n;
}

//A beer can pyramid will square the number of cans in each level - 1 can in the top level, 4 in the second, 9 in the next, 16, 25...
//Function to returns the number of complete levels of a beer can pyramid you can make
int beeramid(int bonus, double price)
{
  double n = 0;
  int i = 0;
  while(n < bonus){
    i++;
    for(int u = 0; u<i*i; u++)
      n += price;
  }
  if(n > bonus && bonus > 0)
    i--;
  return i;
}

//Function which formats a duration, given as a number of seconds, in a human - friendly way
string format_duration(int seconds) {
    string res = "";
    if(seconds == 0)
        return "now";
    int isone = 0;
    array<int, 5> dat = { ((seconds - seconds % 31536000)/ 31536000), ((seconds % 31536000 - (seconds % 86400)) / 86400), ((seconds % 31536000 % 86400 - (seconds % 3600)) / 3600), ((seconds % 31536000 % 86400 % 3600 - (seconds % 60 )) / 60), (seconds % 31536000 % 86400 % 3600 % 60) };
    cout << dat[0] << "\n" << dat[1] << "\n" << dat[2] << "\n" << dat[3] << "\n" << dat[4];
    for (int i = 0; i < 5; i++) {
        if (dat[i] > 0) {
            res += to_string(dat[i]);
            isone++;
            switch (i)
            {
            case 0:
                res += " year";
                break;
            case 1:
                res += " day";
                break;
            case 2:
                res += " hour";
                break;
            case 3:
                res += " minute";
                break;
            case 4:
                res += " second";
                break;
            }
            if (dat[i] != 1) {
                res += "s";
            }
            res += ", ";
        }
    }
    res = res.substr(0, res.length() - 2);
    if (isone > 1) {
        size_t a = res.find_last_of(",");
        string res2 = " and";
        res2 += res.substr(a + 1, res.length() - a);
        res = res.substr(0, a);
        res += res2;
    }
    return res;
}