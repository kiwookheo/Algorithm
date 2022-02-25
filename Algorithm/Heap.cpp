#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x) {
	heap[sz + 1] = x;
	int idx;
	idx = sz + 1;
	sz++;
	while (heap[idx] < heap[idx / 2]) {
		swap(heap[idx], heap[idx / 2]);
		idx /= 2;
		if (idx == 1)
			return;
	}
 }

int top() {
	return heap[1];
}

void pop() {
	swap(heap[1], heap[sz]);
	heap[sz] = 0;
	sz--;
  	int idx = 1;
	while (heap[idx] > heap[idx * 2] || heap[idx] > heap[idx * 2 + 1]) {
		if (heap[idx * 2] <= heap[idx * 2 + 1] || heap[idx * 2 + 1] == 0) {
			swap(heap[idx], heap[idx * 2]);
			idx = idx * 2;
		}
		else {
			swap(heap[idx], heap[idx * 2 + 1]);
			idx = idx * 2 + 1;
		}
		if (idx*2 >= sz)
			return;
	}
}

void test() {
	push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
	cout << top() << '\n'; // 2
	pop(); // {10, 5, 9}
	pop(); // {10, 9}
	cout << top() << '\n'; // 9
	push(5); push(15); // {10, 9, 5, 15}
	cout << top() << '\n'; // 5
	pop(); // {10, 9, 15}
	cout << top() << '\n'; // 9
}

int main() {
	test();
}