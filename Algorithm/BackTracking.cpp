#include <bits/stdc++.h>
using namespace std;

int main() {
	//숫자 3개 1~3 오름차순 조합
	int a[3] = { 1,2,3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << '\n';
	} while (next_permutation(a, a + 3));

	cout << '\n';

	//숫자 2개 1~4 오름차순 조합
	int b[4] = { 0,0,1,1 };
	do {
		for (int i = 0; i < 4; i++) {
			if (b[i] == 0)
				cout << i + 1;
		}
		cout << '\n';
	} while (next_permutation(b, b + 4));

	cout << '\n';

	//숫자 3개 1~5 오름차순 조합
	int c[5] = { 0,0,0,1,1 };
	do {
		for (int i = 0; i < 5; i++) {
			if (c[i] == 0)
				cout << i + 1;
		}
		cout << '\n';
	} while (next_permutation(c, c + 5));
}