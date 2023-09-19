#include <iostream>
#include <queue>
using namespace std;

int N, M;
int visited[2001];
int v[2001][2001];

void BFS(int x) {
	visited[x] = 1;
	queue<int> q;
	q.push(x);
	
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		
		for(int i=1; i<=N; i++) {
			// 방문한 적이 없고, 양방향 간선이 존재한다면,
			if(visited[i]==0 && v[c][i]==1 && v[i][c]==1) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	// 인접 행렬을 통해 간선 생성
	for(int i=0; i<M; i++) {
		int s, e;
		cin >> s >> e;
		
		v[s][e] = 1;
	}
	
	// cnt: 연합의 수
	int cnt=0;
	for(int i=1; i<=N; i++) {
		if(visited[i]==0) {
			cnt++;
			BFS(i);
		}
	}
	
	cout << cnt;
	
	return 0;
}

