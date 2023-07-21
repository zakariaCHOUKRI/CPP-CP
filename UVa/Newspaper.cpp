// UVa 11340 - Newspaper

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, m;
    long long totalPrice;
    unordered_map<char, int> mape;
    string input;

    char inp;
    int price;

    cin >> n;

    while (n--) {

        totalPrice = 0;
        mape.clear();

        cin >> k;
        while (k--){
            cin >> inp >> price;
            mape.emplace(inp, price);
        }

        cin >> m;
        cin.ignore();

        while (m--) {
            getline(cin, input);
            for (int i=0; i<input.size(); i++) if (mape.count(input[i]) > 0) totalPrice += mape[input[i]];
        }

        cout << std::setprecision(2) << std::fixed;
        cout << (double) totalPrice / 100 << "$" << endl;

    }

    return 0;
}