#include <iostream>
#include <vector>

using namespace std;

// Define the maximum size of the array
const long long MAX_N = 100000;

// Define the segment tree and lazy arrays
vector<long long> tree(4 * MAX_N);
vector<long long> lazy(4 * MAX_N);

// Build the segment tree
void build(long long node, long long start, long long end, vector<long long>& arr) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    long long mid = (start + end) / 2;
    build(2 * node, start, mid, arr);
    build(2 * node + 1, mid + 1, end, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Update a range with lazy propagation
void updateRange(long long node, long long start, long long end, long long l, long long r, long long val) {
    if (lazy[node] != 0) {
        // Update this node
        tree[node] += lazy[node] * (end - start + 1);

        // If not a leaf node, propagate the lazy value to its children
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        // Reset the lazy value for this node
        lazy[node] = 0;
    }

    // No overlap
    if (start > r || end < l)
        return;

    // Total overlap
    if (start >= l && end <= r) {
        tree[node] += val * (end - start + 1);

        // If not a leaf node, propagate the lazy value to its children
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }

        return;
    }

    // Partial overlap, update the children
    long long mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);

    // Update the current node based on its children
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Query the current value of an element
long long query(long long node, long long start, long long end, long long idx) {
    if (lazy[node] != 0) {
        // Update this node
        tree[node] += lazy[node] * (end - start + 1);

        // If not a leaf node, propagate the lazy value to its children
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        // Reset the lazy value for this node
        lazy[node] = 0;
    }

    // No overlap
    if (start > idx || end < idx)
        return 0;

    // Leaf node
    if (start == end)
        return tree[node];

    // Partial overlap, query the children
    long long mid = (start + end) / 2;
    long long left = query(2 * node, start, mid, idx);
    long long right = query(2 * node + 1, mid + 1, end, idx);

    return left + right;
}

int main() {

	vector<long long> arr(200005, 0);

	long long n, q, op, a, b, u, k;
	cin >> n >> q;

	for (long long i=0; i<n; i++) {
		cin >> arr[i];
	}

	build(1, 0, n - 1, arr);

	for (long long i=0; i<q; i++) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> u;
			updateRange(1, 0, n - 1, a-1, b-1, u);
		}
		else {
			cin >> k;
			cout << query(1, 0, n - 1, k-1) << endl;
		}
	}


    return 0;
}
