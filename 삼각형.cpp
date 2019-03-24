#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main() {
	int N, len, val,left, right,ans;
	vector<int> rec, dp;

	scanf("%d", &N);
	len = N * (N + 1)/2;

	rec.push_back(0);
	for (int i = 0; i < len; i++) {
		scanf("%d", &val);
		rec.push_back(val);
	}
	dp = rec;
	for (int n = 2; n < N + 1; n++) {
		for (int k = 0; k < n; k++) {
			left= right	= rec[(n - 1)*n / 2 + 1 + k];
			if (k > 0) {
				left += dp[(n - 1)*n / 2 + 1 + k - n];
			}
			if (k < n - 1) {
				right += dp[(n - 1)*n / 2 + 1 + k - n + 1];
			}
			dp[(n - 1)*n / 2 + 1 + k] = max(left, right);
		}
	}
	printf("%d", *max_element(dp.begin(), dp.end()));
	return 0;

}