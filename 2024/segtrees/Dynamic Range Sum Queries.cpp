#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sz;

class SegTree {

    struct Node {
        ll val;
        Node (ll v = 0) {
            val = v;
        }
    };

    vector<Node> seg;

public:

    SegTree(ll n) {
        sz = n;
        seg.resize(4*n);
    }

    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = L.val + R.val;
        return res;
    }

    void upd(ll idx, ll val, ll p=1, ll st=1, ll en=sz) {
        if (st == en) {
            seg[p] = val;
            return;
        }

        ll mi = (st + en) / 2;
        if (idx <= mi) {
            upd(idx, val, 2*p, st, mi);
        } else {
            upd(idx, val, 2*p+1, mi+1, en);
        }

        seg[p] = merge(seg[2*p], seg[2*p+1]);
    }

    Node get(ll l, ll r, ll p=1, ll st=1, ll en=sz) {
        if (l <= st && r >= en) return seg[p];
        if (l > en || r < st) return Node();
        ll mi = (en + st) / 2;
        Node L = get(l, r, 2*p, st, mi);
        Node R = get(l, r, 2*p+1, mi+1, en);
        return merge(L, R);
    }

};


int main() {
    ll n, q, x, a, b;
    cin >> n >> q;
    SegTree st(n+10);
    for (ll i=1; i<=n; i++) {
        cin >> x;
        st.upd(i, x);
    }
    while (q--) {
        cin >> x >> a >> b;
        if (x == 1) {
            st.upd(a, b);
        } else {
            cout << st.get(a, b).val << endl;
        }
    }
    return 0;
}