#include <bits/stdc++.h>

using namespace std;

struct Contestant {
    string nickname;
    int score;
    int matches;
    string joinDate;
};

bool compareContestants(const Contestant& a, const Contestant& b) {
    if (a.score != b.score)
        return a.score > b.score;
    if (a.matches != b.matches)
        return a.matches > b.matches;
    if (a.joinDate != b.joinDate)
        return a.joinDate < b.joinDate;
    return a.nickname < b.nickname;
}

int main() {
    int N;
    cin >> N;

    vector<Contestant> contestants(N);

    for (int i = 0; i < N; ++i) {
        cin >> contestants[i].nickname >> contestants[i].score >> contestants[i].matches >> contestants[i].joinDate;
    }

    sort(contestants.begin(), contestants.end(), compareContestants);

    for (int i = 0; i < N; ++i) {
        cout << contestants[i].nickname << " " << contestants[i].score << " " << contestants[i].matches << " " << contestants[i].joinDate << endl;
    }

    return 0;
}
