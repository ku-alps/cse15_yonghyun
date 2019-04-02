#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n,ip, ans=0, i = 0;
	scanf("%d", &n);
	vector <int>A;
	vector <int>B;

	while (i < 2) {
		for (int k = 0; k < n; k++) {
			scanf("%d", &ip);
			if (i == 1) A.push_back(ip);
			else B.push_back(ip);
		}
		i++;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (i = 0; i < n; i++) {
		ans += A[i] * B[i];
	}
	printf("%d", ans);
	return 0;
}