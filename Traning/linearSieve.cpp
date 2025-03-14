#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e7 + 10;

int lpd[maxN];
vector<int> primes;

void linearSieve() {
    for (int i = 2; i < maxN; i++) {
        if (lpd[i] == 0) {
            lpd[i] = i;
            primes.push_back(i);
        }

        for (int prime: primes) {
            if (prime * i > maxN) {
                break;
            }
            lpd[prime * i] = prime;
            if (lpd[i] == prime) {
                break;
            }
        }
    }
}