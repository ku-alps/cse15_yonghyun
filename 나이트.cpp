#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


typedef struct Node {
	int xpos;
	int ypos;
}node;

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void bfs(vector <vector <int>> &v,node start, node end, int len) {
	int x, y,nx,ny;
	queue <node> q;
	q.push(start);
	v[start.xpos][start.ypos] = 0;

	while (!q.empty()) {
		x = q.front().xpos;
		y = q.front().ypos;
		q.pop();

		for (int i = 0; i < 8; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (ny >= 0 && nx >= 0 && ny < len && nx < len) {
				if (v[nx][ny] == -1) {
					node p = { nx,ny };
					q.push(p);
					v[nx][ny] = v[x][y] + 1;
					if (nx == end.xpos && ny == end.ypos) {
						printf("%d \n", v[nx][ny]);
						return;
					}
				}
			}
		}
	}

}

int main() {
	int n, len;
	node s, e;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &len);
		scanf("%d %d", &s.xpos, &s.ypos);
		scanf("%d %d", &e.xpos, &e.ypos);
		vector <vector <int>> map(len, vector<int>(len, -1));
		if (s.xpos == e.xpos && s.ypos == e.ypos) printf("0\n");
		else bfs(map, s, e, len);
	}

}