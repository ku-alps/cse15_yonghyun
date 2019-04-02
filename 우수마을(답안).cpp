#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector <int> val;

int dfs(vector<int> &visited,vector <int> tree[],int v, bool flag) {
	int ans = 0;
	visited[v] = 1;

	for (int i = 0; i < tree[v].size(); i++) {
		int next = tree [v][i]; //다음 마을
		if (visited[next]) continue; //이미 방문했으면 continue
		//현재마을이 우수마을인 경우
		if (flag) {
			ans += dfs(visited, tree, next, 0);
		}
		//현재마을이 우수마을이 아닌 경우
		else {
			ans += max(dfs(visited, tree, next, 0), dfs(visited, tree, next, 1) + val[next-1]);
		}
	}

	visited[v] = 0;
	return ans;
}


int main() {
	int n, p ,ans;
	pair <int, int> node;
	scanf("%d", &n);

	vector <int> tree[10007];
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		val.push_back(p);
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &node.first, &node.second);
		tree[node.first].push_back(node. second);
		tree[node.second].push_back(node.first);
	}
	vector <int> visit(n+1);
	ans = max(dfs(visit, tree, 1, 0), dfs(visit,tree,1,1)+val[0]);
	printf("%d", ans);
	
	return 0;
}