#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, h, t, o;
    cin >> n;

    h = n/100;
    t = n/10 - h*10;
    o = n - h*100 - t*10;


    while (h*t < o || h*t >= 10) {

        if (h*t >= 10) {
            n = (h+1)*100;
        } else {
            n = h*100 + (t+1)*10;
        }

        h = n/100;
        t = n/10 - h*10;
        o = n - h*100 - t*10;
    }
    cout << h << t << h*t << endl;


    return 0;
}