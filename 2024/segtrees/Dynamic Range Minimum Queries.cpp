#include <bits/stdc++.h>

using namespace std;

int sz;

class SegTree {

    struct Node {
        int val;
        Node(int v=2e9) {
            val=v;
        }
    };

    vector<Node> seg;

public:

    SegTree(int n) {
        sz = n;
        seg.resize(4*n);
    }

    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = min(L.val, R.val);
        return res;
    }

    void upd(int idx, int val, int p = 1, int st = 1, int en = sz) {

        if (st == en) {
            seg[p] = Node(val);
            return;
        }

        int mi = (st + en) / 2;
        if (idx <= mi) {
            upd(idx, val, 2*p, st, mi);
        } else {
            upd(idx, val, 2*p + 1, mi+1, en);
        }

        seg[p] = merge(seg[2*p], seg[2*p + 1]);
    }

    Node get(int l, int r, int p = 1, int st = 1, int en = sz) {
        if (l <= st && r >= en) return seg[p];
        if (l > en || r < st) return Node();
        int mi = (st + en) / 2;
        Node L = get(l, r, 2*p, st, mi);
        Node R = get(l, r, 2*p + 1, mi+1, en);
        return merge(L, R);
    }
};

int main() {

    int n, q, x, k, u, a, b;

    cin >> n >> q;
    SegTree st(n+10);

    for (int i=1; i<=n; i++) {
        cin >> x;
        st.upd(i, x);
    }

    while (q--) {
        cin >> x;
        if (x == 1) {
            cin >> k >> u;
            st.upd(k, u);
        } else {
            cin >> a >> b;
            cout << st.get(a, b).val << endl;
        }
    }

    return 0;
}