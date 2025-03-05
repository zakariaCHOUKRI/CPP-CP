#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

    sor3a
    //freopen("brimore.in","r",stdin);


    int T;
    std::cin >> T;
    
    constexpr double PI = 3.14159265358979323846;
    
    while (T--) {
        int u;
        std::cin >> u;
        
        // We iterate over possible y values and compute the corresponding distances
        int best_y = 0;
        int min_distance = INT_MAX;
        
        // We try different values of y to find the minimal distance
        for (int y = 0; y <= u; ++y) {
            double distance = (PI * u / 2) + (PI * y / 2);
            int rounded_distance = std::round(distance);
            if (rounded_distance < min_distance) {
                min_distance = rounded_distance;
                best_y = y;
            }
        }
        
        // Output the best y and the minimal distance
        std::cout << std::fixed << std::setprecision(0) << best_y << " " << min_distance << std::endl;
    }


    return 0;
}