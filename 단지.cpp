#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int k = 0;
vector <int> ans;
int visit[25][25] = {0};

void dfs(vector <vector <int>> &v ,int x, int y, int n) {
	ans[k]++;
	visit[x][y] = 1;
	if ((x+1) < n && y >= 0 && v[x + 1][y] == 1 && visit[x+1][y] != 1) {
		dfs(v, x + 1, y ,n);
	}
	if ((x - 1) >= 0 && y >= 0 && v[x - 1][y] == 1 && visit[x - 1][y] != 1) {
		dfs(v, x - 1, y ,n);
	}
	if (x >= 0 && (y - 1) >= 0 && v[x][y - 1] == 1 && visit[x][y-1] != 1) {
		dfs(v, x, y - 1 , n);
	}
	if (x >= 0 && (y + 1) < n && v[x][y + 1] == 1 && visit[x][y + 1] != 1) {
		dfs(v, x, y + 1 , n);
	}
}
int main() {
	int n,i,j;
	scanf("%d", &n);
    vector <vector <int>> map(n, vector<int>(n));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] != 1) {
				ans.push_back(0);
				dfs(map, i, j, n);
				k++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}