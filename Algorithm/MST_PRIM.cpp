#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mst[101];
bool chk[101] = { 0 };

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mst[a].push_back({ c,b });
		mst[b].push_back({ c,a });
	}
	chk[1] = 1;
	priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for (auto nxt : mst[1]) 
		pq.push(nxt);

	int sum = 0;
	int cnt = 0;

	while (cnt < v - 1) {
		pair<int, int> p = pq.top(); pq.pop();
		if (chk[p.second] != 0) continue;
		sum += p.first;
		chk[p.second] = 1;
		cnt++;
		for (auto nxt : mst[p.second]) {
			if (chk[nxt.second] == 0) 
				pq.push(nxt);
		}
	}
	cout << sum;
}