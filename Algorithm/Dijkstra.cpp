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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �켱���� ť�� �Ÿ��� ���� ������ ����

	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // ���� �켱���� ť���� ���� �ִ� �Ÿ��� d �ִ� ��� ���̺��� ���� �ٸ� ��� (�켱���� ť���� ���� ���� �ִ� ��ΰ� �ƴ� ���) continue
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; // ���� �ִ� ��� ���̺��� ���� �� ���� �� continue;
			d[nxt.second] = d[cur.second] + nxt.first; // ���� �������� ���� �ִ� ��� �� ����
			pq.push({ d[nxt.second], nxt.second }); // �ִ� ��η� �����Ǹ� pq�� push
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}