#include <bits/stdc++.h>

using namespace std;

// Function to check if all rows have at most one bead (O)
bool atMostOneBeadPerRow(int m[], int n) {
  for (int i = 1; i <= n; i++) {
    if (m[i] > 1) {
      return false;
    }
  }
  return true;
}

int main() {
  string r1, r2, r3, r4, p1, p2;
  int t, norows, m[10];

  cin >> t;
  while (t--) {
    cin >> r1 >> r2 >> r3 >> r4 >> p1 >> p2;

    norows = 0;
    memset(m, 0, sizeof m);

    // Count remaining beads (Os) in each row
    for (int i = 0; i < r1.size(); i++) {
      if (r1[i] == 'O') {
        m[1]++;
      }
    }
    for (int i = 0; i < r2.size(); i++) {
      if (r2[i] == 'O') {
        m[2]++;
      }
    }
    for (int i = 0; i < r3.size(); i++) {
      if (r3[i] == 'O') {
        m[3]++;
      }
    }
    for (int i = 0; i < r4.size(); i++) {
      if (r4[i] == 'O') {
        m[4]++;
      }
    }

    if (atMostOneBeadPerRow(m, 4)) {
      cout << p1 << " wins" << endl;
    } else {
      int grundy_value = 0;
      for (int i = 1; i <= 4; i++) {
        if (m[i] > 1) {
          grundy_value ^= m[i];
        }
      }

      if (grundy_value != 0) {
        cout << p1 << " wins" << endl;
      } else {
        cout << p2 << " wins" << endl;
      }
    }
  }

  return 0;
}
