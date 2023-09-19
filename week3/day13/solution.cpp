// BFS를 통한 풀이

#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int N, K;
int M[1001][1001];
int visited[1001][1001];
int cnt[31];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

// 건물의 유형이 num인 건물 탐색
void BFS(int x, int y, int num) {
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = 1;
	int tmp = 0;
	
	while(!q.empty()) {
		pii c = q.front();
		q.pop();
		tmp++;
		
		for(int i=0; i<4; i++) {
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N && visited[nx][ny]==0 && M[nx][ny]==num) {
				visited[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	
	// 건물이 K개 이상인 경우, 개수 증가
	if(tmp >= K) cnt[num]++;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> M[i][j];
		}
	}
	
	// 방문한 적 없는 건물일 경우, 탐색
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(visited[i][j]==0) {
				BFS(i, j, M[i][j]);
			}
		}
	}

	// ans: 최대값을 가지는 건물의 유형, tmp: 최대값
	int ans = 30, tmp = 0;
	for(int i=0; i<=30; i++) {
		if(tmp <= cnt[i]) {
			tmp = cnt[i];
			ans = i;
		}
	}
	cout << ans;
	
	return 0;
}