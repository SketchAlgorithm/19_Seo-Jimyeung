#include <iostream>
#include <vector>

using namespace std;

vector<int>* r;
int n, t;
bool ans = false;

void dfs(int target) {
	
	for (int i = 0; i < r[target].size(); i++) {
		int k = r[target].at(i);
		if (k == 1) {
			ans = true;
			return;
		}
		dfs(k);
	}
}

int main() {
	cin >> n >> t;
	r = new vector<int>[n + 1];
	int a;
	for (int i = 1; i <= n - 1; i++) { // vector에 역방향으로 값을 넣음.
		cin >> a;
		r[i + a].push_back(a);
	}
	dfs(t);
	if (ans) { 
		cout << "YES" << endl; 
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}