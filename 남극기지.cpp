#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Point {
public:
	double x;
	double y;

};

int N; // 기지의 수
bool checked[100];
Point points[100];
double cost[2000][2000];
double dist[100];

double getDist(Point p1, Point p2) {
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(x * x + y * y);
}

double getMax(double& a, double& b) {
	if (a >= b) { return a; }
	return b;
}

double getMin(double& a, double& b) {
	if (a <= b) { return a; }
	return b;
}


double search() {
	for (int i = 0; i < N; i++) {
		dist[i] = 2000.0;
		checked[i] = false;
	}
	double ans = 0.0;
	dist[0] = 0.0;

	while (true) {
		int k = 0;
		for (int i = 1; i < N; i++) {
			if (!checked[i]) {
				if (k == 0 || dist[i] < dist[k]) {
					k = i;
				}
			}
		}
		if (k == 0) { break; }
		checked[k] = true;

		ans = getMax(dist[k], ans);
		for (int i = 0; i < N; i++) {
			dist[i] = getMin(dist[i], cost[k][i]);
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> points[i].x >> points[i].y;
		}
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				double D = getDist(points[i], points[j]);

				cost[i][j] = D;
				cost[j][i] = D;
			}
		}

		double ans = search();

		cout << ans << endl;
	}
	


	return 0;
}