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

public:

    SegTree(int n) {
        sz = n;
        seg.resize(4<<__lg(n));
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

        int mi = (st + en) >> 1;
        if (idx <= mi) {
            upd(idx, val, p << 1, st, mi);
        } else {
            upd(idx, val, p << 1 | 1, mi + 1, en);
        }

        seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
    }

    Node get(int l, int r, int p = 1, int st = 1, int en = sz) {
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
        st.upd(i, x);
    }

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << st.get(l, r).val << '\n';
        }
        else {
            int idx, v; cin >> idx >> v;
            st.upd(idx, v);
        }
    }
    return 0;
}
