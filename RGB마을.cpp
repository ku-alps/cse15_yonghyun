#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int n, r, g, b, val1,val2;
	scanf("%d", &n);
	vector <vector <int>> hou(n, vector<int>(3));
	vector <vector <int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		hou[i] = { r,g,b };
	}
	dp = hou;
	for (int i =1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			val1 = val2 = hou[i][j];
			if (j == 0) {
				if (val1 + dp[i - 1][1] > val2 + dp[i - 1][2]) dp[i][j] = val1 + dp[i - 1][2];
				else dp[i][j] = val2 + dp[i - 1][1];
			}
			else if (j == 1) {
				if (val1 + dp[i - 1][0] > val2 + dp[i - 1][2]) dp[i][j] = val1 + dp[i - 1][2];
				else dp[i][j] = val2 + dp[i - 1][0];
			}
			else {
				if (val1 + dp[i - 1][0] > val2 + dp[i - 1][1]) dp[i][j] = val1 + dp[i - 1][1];
				else dp[i][j] = val2 + dp[i - 1][0];
			}
		}
	}
	vector <int> ans(&dp[n - 1][0], (&dp[n - 1][2])+1);
	printf("%d", *min_element(ans.begin(), ans.end()));
	return 0;
}