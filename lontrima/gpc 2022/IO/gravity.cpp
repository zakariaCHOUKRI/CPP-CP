#include <bits/stdc++.h>

using namespace std;

int main() {

    int tCount, force;
    string planet;
    double g;

    cin >> tCount;

    while (tCount--) {

        cin >> force >> planet >> g;

        cout << "Earth " << force << "0N " << planet << " " << fixed << setprecision(1) << g*force << "N\n";



    }



    return 0;
}