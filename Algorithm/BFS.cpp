#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
bool vis[502][502]; // �ش� ��ǥ �湮 ���� ����
int n = 7, m = 10; // �˻��� ��� ��
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> q;
	vis[0][0] = 1;
	q.push({ 0,0 });
	int dir,nx,ny;//�����¿� üũ ����
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (dir = 0; dir < 4; dir++) {
			nx = cur.X + dx[dir];
			ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}