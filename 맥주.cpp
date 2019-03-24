#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct Node {
	int xpos;
	int ypos;
}node;

int dist(node a, node b) {
	int dist = abs(a.xpos - b.xpos) + abs(a.ypos - b.ypos);
	return dist;
}
void check(vector<node> v, node s, node e) {
	queue <node> q;
	q.push(s);
	int visit[100] = { 0 };
	while (!q.empty()) {
		int nx = q.front().xpos;
		int ny = q.front().ypos;
		node n = { nx,ny };
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			if (dist(n, v[i]) <= 1000 && visit[i] == 0) {
				q.push(v[i]);
				visit[i] = 1;
			}
			else if (dist(n, e) <= 1000) {
				printf("happy\n");
				return;
			}
		}
	}
	printf("sad\n");
	return;
	
}

int main() {
	int n, cnt;
	node input,s,e;
	scanf("%d", &n);
	vector <node> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &cnt);
		scanf("%d %d", &s.xpos, &s.ypos);
		for (int j = 0; j < cnt; j++) {
			scanf("%d %d", &input.xpos, &input.ypos);
			m.push_back(input);
		}
		scanf("%d %d", &e.xpos, &e.ypos);
		check(m, s, e);
		m.clear();
	}

	return 0;
}
