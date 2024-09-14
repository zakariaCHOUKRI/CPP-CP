#include <bits/stdc++.h>

using namespace std;

vector<int> calculateLPS(string pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }

    return lps;
}

vector<int> kmp(string str, string pat) {
    int n = str.length();
    int m = pat.length();
    vector<int> lps = calculateLPS(pat);
    vector<int> indices;

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pat[j] == str[i]) {
            i++;
            j++;
        }

        if (j == m) {
            indices.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != str[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return indices;
}

int main() {

    string str, pat;

    cin >> str;
    cin >> pat;

    cout << kmp(str, pat).size() << endl;

    string s = "abcxxhjabcjabcxxlkazjeabcxxhjiko";
    vector<int> test = calculateLPS(s);
    for (int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    for (int i=0; i<test.size(); i++) {
        cout << test[i] << " ";
    }

    return 0;
}