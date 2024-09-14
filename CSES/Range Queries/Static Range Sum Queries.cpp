#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
int a, b, n, q, arr[MAXN];
ll t[4*MAXN];

void build(int v, int tl, int tr) {

	if (tl == tr) {
		t[v] = arr[tl];
	}
	else {
		int tm = (tl + tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

ll somme(int v, int tl, int tr, int l, int r) {
	
	if (l > r) {
		return 0;
	}

	if (tl == l && tr == r) {
		return t[v];
	}

	int tm = (tl + tr)/2;
	return somme(v*2, tl, tm, l, min(r, tm)) + somme(v*2+1, tm+1, tr, max(tm+1, l), r);

}

int main() {

	cin >> n >> q;

	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	build(1, 1, n);

	for (int i=1; i<=q; i++) {
		cin >> a >> b;
		cout << somme(1, 1, n, a, b) << endl;
	}

	return 0;
}
