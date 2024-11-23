#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, dp[1000005];

unordered_set<int> digits(ll number) {
    unordered_set<int> digitSet;
    while (number > 0) {
        int digit = number % 10;
        digitSet.insert(digit);
        number /= 10;
    }
    return digitSet;
}

int answer(int number) {

    if (number == 0) {
        return 0;
    }

    if (number < 10) {
        return 1;
    }

    if (dp[number] != -1) {
        return dp[number];
    }

    int val = INT_MAX;

    for (int digit: digits(number)) {
        if (digit != 0 && number - digit >= 0) {
            val = min(val, answer(number - digit));
        }
    }

    dp[number] = val + 1;
    return dp[number];
}

int main() {

    cin >> n;

    memset(dp, -1, sizeof dp);

    cout << answer(n);

    return 0;
}