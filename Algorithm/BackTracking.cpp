#include <bits/stdc++.h>
using namespace std;

int main() {
	//���� 3�� 1~3 �������� ����
	int a[3] = { 1,2,3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << '\n';
	} while (next_permutation(a, a + 3));

	cout << '\n';

	//���� 2�� 1~4 �������� ����
	int b[4] = { 0,0,1,1 };
	do {
		for (int i = 0; i < 4; i++) {
			if (b[i] == 0)
				cout << i + 1;
		}
		cout << '\n';
	} while (next_permutation(b, b + 4));

	cout << '\n';

	//���� 3�� 1~5 �������� ����
	int c[5] = { 0,0,0,1,1 };
	do {
		for (int i = 0; i < 5; i++) {
			if (c[i] == 0)
				cout << i + 1;
		}
		cout << '\n';
	} while (next_permutation(c, c + 5));
}