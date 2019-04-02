#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> cnt(n);
	cnt[0] = 1, cnt[1] = 2;
	for (int i = 2; i < n; i++) {
		cnt[i] = (cnt[i - 1] + cnt[i - 2]) % 10007;
	}
	printf("%d", cnt[n - 1] );
	return 0;

}