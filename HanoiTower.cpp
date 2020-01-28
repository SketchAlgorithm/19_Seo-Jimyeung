#include <iostream>
#include <queue>

using namespace std;

int N;
int c = 0;
queue<int> q;

void hanoi(int n, int start, int mid, int end) {
	c++;
	if (n == 1) {
		q.push(start);
		q.push(end);
	}
	else {
		hanoi(n - 1, start, end, mid);
		q.push(start);
		q.push(end);
		hanoi(n - 1, mid, start, end);
	}
}

int main() {
	cin >> N;
	hanoi(N, 1, 2, 3);
	cout << c << endl;
	while(!q.empty()) {
		cout << q.front();
		q.pop();
		cout << " " << q.front() << endl;
		q.pop();
	}

	return 0;
}