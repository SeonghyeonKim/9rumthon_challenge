#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int N, M, S, E;
vector<int> edge[1001];

// t번 도시가 공사 중일때 탐색
void BFS(int t) {
	vector<int> visited(N+1, 0);
	visited[S] = 1;
	// t번 도시도 방문했다고 가정
	visited[t] = 1;
	queue<pii> q;
	q.push({S, 1});
	
	while(!q.empty()) {
		pii c = q.front();
		q.pop();
		
		for(int i=0; i<edge[c.first].size(); i++) {
			int n = edge[c.first][i];
			
			if(visited[n]==0) {
				// 도착한 경우 도시 수 출력후 반환
				if(n==E) {
					cout << c.second+1 << "\n";
					return ;
				}
				
				visited[n]=1;
				q.push({n, c.second+1});
			}
		}
	}
	
	// 도착하지 못했을 경우
	cout << "-1\n";
	return ;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> S >> E;
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1; i<=N; i++) {
		// 출발/도착 도시가 공사 중인 경우, 도달 불가
		if(S==i || E==i) {
			cout << "-1\n";
			continue;
		}
		BFS(i);
	}
	
	return 0;
}