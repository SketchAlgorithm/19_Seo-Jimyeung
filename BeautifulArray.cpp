#include <iostream>
#include <math.h>

using namespace std;

int number, x;
int a[30001];
int ans = 0;
int dp[30001][30001];

int getMax(int k, int t) {
	if (k > t) {
		return k;
	}
	else {
		return t;
	}
}

int main() {
	cin >> number >> x;
	for (int i = 1; i <= number; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= number; i++)
	{
		dp[i][0] = getMax(dp[i - 1][0] + a[i], a[i]); // 합이 최대
		dp[i][1] = getMax(getMax(dp[i - 1][1] + a[i] * x, dp[i - 1][0] + a[i] * x), a[i] * x); // 곱한 합 최대
		dp[i][2] = getMax(getMax(getMax(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]), dp[i - 1][0] + a[i]), a[i]); // 어떤 것을 선택?
		ans = getMax(ans, getMax(dp[i][0], getMax(dp[i][1], dp[i][2])));
	}
	cout << ans << endl;

	return 0;
}