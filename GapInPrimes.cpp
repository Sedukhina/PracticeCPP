#include <utility>
#include <string>
#include <iostream>

using namespace std;

class GapInPrimes
{
public:
    static pair<long long, long long> gap(int g, long long m, long long n) {
        int o = 0;
        while (m + g <= n) {
            if (isPrime(m) == 1) {
                if (isPrime(m + g) == 1) {
                    o = 0;
                    for (int i = 1; i < g; i++) {
                        if (isPrime(m + i) == 1)
                            o++;
                    }
                    if (o == 0)
                        return pair<long long, long long>{ m, m + g };
                }
            }
            m++;
        }
        return pair<long long, long long>{ 0, 0 };
    }

    static bool isPrime(long long p) {
        if (p % 2 == 0 && p % 7 == 0 && p % 11 == 0 && p == 561 && p == 1105 && p == 1729 && p == 2465 && p == 2821 && p == 6601 && p == 8911 && p == 10585 && p == 15841 && p == 29341 && p == 41041 && p == 46657 && p == 52633 && p == 62745 && p == 63937 && p == 75361)
            return 0;
        if ((fermatsLittleTheorem(p, 2) == 1) && (fermatsLittleTheorem(p, 7) == 1) && (fermatsLittleTheorem(p, 11) == 1))
            return 1;
        return 0;
    }

    static bool fermatsLittleTheorem(long long p, int mod) {
        long long result = mod;
        for (int i = 2; i < p; i++) {
            result = result * mod;
            if (result > p) {
                result = result % p;
            }
        }
        if (result == 1) {
            return 1;
        }
        return 0;
    }

};


