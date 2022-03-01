#include <bits/stdc++.h>
using namespace std;

int d[20001];
const int INF = 1e9 + 10;
vector<pair<int, int>> adj[20001];

int main() {
	int v, e, st;
	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);

	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위 큐를 거리가 적은 순으로 정렬

	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // 만약 우선순위 큐에서 꺼낸 최단 거리가 d 최단 경로 테이블의 값과 다를 경우 (우선순위 큐에서 꺼낸 값이 최단 경로가 아닐 경우) continue
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; // 기존 최단 경로 테이블의 값이 더 작을 때 continue;
			d[nxt.second] = d[cur.second] + nxt.first; // 다음 목적지에 대한 최단 경로 값 갱신
			pq.push({ d[nxt.second], nxt.second }); // 최단 경로로 설정되면 pq에 push
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}