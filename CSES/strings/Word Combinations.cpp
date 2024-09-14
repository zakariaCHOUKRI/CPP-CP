#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

struct TrieNode{

    struct TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i=0; i<26; i++) {
            child[i] = NULL;
        }
    }
};

TrieNode* root;

bool searchString(string str) {

    TrieNode *curr = root;
    ll n = str.length();
    for (ll i=0; i<n; i++) {
        int idx = str[i] - 'a';
        if (curr->child[idx] == NULL) {
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEnd;
}

void insertString(string str) {

    TrieNode *curr = root;
    ll n = str.length();
    for (ll i=0; i<n; i++) {
        int idx = str[i] - 'a';
        if (curr->child[idx] == NULL) {
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

int main() {

    int k;
    string s, pat;

    cin >> s;
    cin >> k;

    ll n = s.length();

    root = new TrieNode();

    for (int i=0; i<k; i++) {
        cin >> pat;
        insertString(pat);
    }

    vector<int> dp(n+1);

    dp[n] = 1;

    for (int i=n-1; i>=0; i--) {
        TrieNode *test = root;
        for (int j=i; j<n; j++) {
            int idx = s[j] - 'a';
            if (test->child[idx] == NULL) {
                break;
            }
            test = test->child[idx];
            if (test->isEnd) {
                dp[i] = dp[i]%mod + dp[j+1]%mod;
                dp[i] = dp[i]%mod;
            }
        }
    }

    cout << dp[0] << endl;


    return 0;
}