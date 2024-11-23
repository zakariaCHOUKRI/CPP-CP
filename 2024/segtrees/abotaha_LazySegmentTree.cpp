#include <bits/stdc++.h>

using namespace std;


int sz;
class SegTree {

    struct Node {
        int val;
        Node(int v = 2e9) {
            val = v;
        }
    };

    vector <Node> seg;
    vector <int> lazy;

public:

    SegTree(int n) {
        sz = n;
        seg.resize(4<<__lg(n));
        lazy.resize(4<<__lg(n), 0); // lazy[p] = 0: means that there is no updates,
                                    // lazy[p] = v: means that there is an update with value v
    }

    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = min(L.val, R.val);
        return res;
    }

    void propagate(int p, int st, int en) {
        if (lazy[p] == 0) return;
        seg[p].val = lazy[p];
        if (st != en) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }

    void upd(int l, int r, int val, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) {
            lazy[p] = val;
            return propagate(p, st, en);
        }
        if (en < l || st > r) return;

        int mi = (st + en) >> 1;
        upd(l, r, val, p << 1, st, mi);
        upd(l, r, val, p << 1 | 1, mi + 1, en);

        seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
    }

    Node get(int l, int r, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) return seg[p];
        if (en < l || st > r) return Node();
        int mi = (st+en)>>1;
        auto L = get(l, r, p << 1, st, mi);
        auto R = get(l, r, p << 1 | 1, mi+1, en);
        return merge(L, R);
    }
};

int main() {
    int n; cin >> n;
    SegTree st(n+10);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st.upd(i, i, x);
    }

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << st.get(l, r).val << '\n';
        }
        else {
            int l, r, v; cin >> l >> r >> v;
            st.upd(l, r, v);
        }
    }
    return 0;
}
