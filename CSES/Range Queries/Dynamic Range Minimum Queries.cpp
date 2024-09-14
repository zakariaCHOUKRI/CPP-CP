#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
int a, b, n, q, op, arr[MAXN];
ll t[4*MAXN];

void build(int v, int tl, int tr) {

	if (tl == tr) {
		t[v] = arr[tl];
	}
	else {
		int tm = (tl + tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

ll somme(int v, int tl, int tr, int l, int r) {
	
	if (l > r) {
		return 1e9 + 1;
	}

	if (tl == l && tr == r) {
		return t[v];
	}

	int tm = (tl + tr)/2;
	return min(somme(v*2, tl, tm, l, min(r, tm)), somme(v*2+1, tm+1, tr, max(tm+1, l), r));

}

void update(int v, int tl, int tr, int pos, int new_val) {
	
	if (tl == tr) {
		t[v] = new_val;
	}
	else {
		int tm = (tl + tr)/2;
		if (pos <= tm) {
			update(v*2, tl, tm, pos, new_val);
		}
		else {
			update(v*2+1, tm+1, tr, pos, new_val);
		}
		t[v] = min(t[v*2], t[v*2+1]);
	}

}

int main() {

	cin >> n >> q;

	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	build(1, 1, n);

	for (int i=1; i<=q; i++) {
		cin >> op >> a >> b;
		if (op == 2) {
			cout << somme(1, 1, n, a, b) << endl;	
		}
		else {
			update(1, 1, n, a, b);
		}
	}

	return 0;
}
