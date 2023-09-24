// UVa 10226 - Hardwood Species

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, total;
    string name;
    map<string, int> dict;

    scanf("%d", &n);
    cin.ignore();
    cin.ignore();
    while (n--) {

        total = 0;
        dict.clear();

        while (getline(cin, name)) {
            if (name == "") break;
            if (!dict.count(name)) dict[name] = 1;
            else dict[name] += 1;
            total++;
        }
        
        for(const auto& elem: dict) {
            printf("%s %.4f\n", elem.first.c_str(), 100* ((float) elem.second / (float) total));
        }
        if (n) printf("\n");

    }

    return 0;
}