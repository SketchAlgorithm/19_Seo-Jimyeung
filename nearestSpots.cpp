#include <iostream>
using namespace std;

int n, a, b;
double ans;
pair<int, int> p[100001];

double dist(pair<int, int> x, pair<int, int> y) {
	double x1 = x.first;
	double y1 = x.second;
	double x2 = y.first;
	double y2 = y.second;

	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p[i].first = a;
		p[i].second = b;
	}
	ans = dist(p[0], p[1]);
}

void nearest(int count) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dist(p[i], p[j]) < ans) {
				ans = dist(p[i], p[j]);
			}
		}
	}
}


int main() {
	input();
	nearest(0);
	cout << ans << endl;

	return 0;
}