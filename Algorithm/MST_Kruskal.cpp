#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> mst[100001];
int parent[10001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else if (a > b) parent[a] = b;
}

bool findParent(int a, int b) {
	return getParent(a) == getParent(b);
}
int main() {
	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mst[i] = { c,a,b };
	}

	sort(mst, mst + e);

	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < e; i++) {
		int a = get<1>(mst[i]);
		int b = get<2>(mst[i]);
		if (findParent(a, b)) continue;
		sum += get<0>(mst[i]);
		unionParent(a, b);
		cnt++;
		if (cnt == v - 1) break;
	}
	cout << sum;
}