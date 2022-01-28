//#include <bits/stdc++.h>
//using namespace std;
//
//#define X first
//#define Y second
//
//int board[502][502] =
//{ {1,1,1,0,1,0,0,0,0,0},
// {1,0,0,0,1,0,0,0,0,0},
// {1,1,1,0,1,0,0,0,0,0},
// {1,1,0,0,1,0,0,0,0,0},
// {0,1,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
//bool vis[502][502]; // 해당 좌표 방문 여부 저장
//int n = 7, m = 10; // 검색할 행과 열
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//
//int main() {
//	int i,nx,ny;
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	stack<pair<int, int>> s;
//	vis[0][0] = 1;
//	s.push({ 0,0 });
//	while (!s.empty()) {
//		pair<int, int> cur = s.top();
//		s.pop();
//		for (i = 0; i < 4; i++) {
//			nx = cur.X + dx[i];
//			ny = cur.Y + dy[i];
//			if (nx < 0 || nx >= 7 || ny < 0 || ny >= 10) continue;
//			if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
//			vis[nx][ny] = 1;
//			s.push({ nx,ny });
//		}
//	}
//}