#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct body {
	int weight;
	int height;
	int k;
}body;

int main() {
	int n,i;
	vector<body> ans;
	body input;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &(input.weight), &(input.height));
		input.k = 1;
		ans.push_back(input);
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i].weight < ans[j].weight && ans[i].height < ans[j].height) {
				ans[i].k++;
			}
		}
	}
	for (i = 0; i < n-1; i++) {
		printf("%d ", ans[i].k);
	}
	printf("%d ", ans[i].k);
	return 0;
}