#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int areas[100005];
int n, m;

bool can_form_nestangle(int s) {
    int count = 1;
    int last_area = areas[0];

    for (int i=1; i<n; i++) {
        if (areas[i] - last_area >= s) {
            count++;
            last_area = areas[i];
        }
        if (count >= m) {
            return true;
        }
    }
    return false;
}

int main() {

    sor3a

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> areas[i];
    }
    cin >> m;

    sort(areas, areas + n);
    int l = 0, r = areas[n-1] - areas[0];
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can_form_nestangle(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
