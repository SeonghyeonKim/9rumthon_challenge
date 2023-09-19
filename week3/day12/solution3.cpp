// stack, dfs를 통한 문제 해결

#include <iostream>
#include <vector>
#include <stack>
#define pii pair<int, int>
using namespace std;

int N;
bool arr[1001][1001];
bool visited[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y) {
	visited[x][y] = 1;
	stack<pii> s;
	s.push({x, y});
	
	while(!s.empty()) {
		pii c = s.top();
		s.pop();
		
		for(int i=0; i<4; i++) {
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];

			// 유효한 범위에 있고, 집이 있으며, 방문하지 않았을 경우
			if(nx>=0 && nx<N && ny>=0 && ny<N && visited[nx][ny]==0 && arr[nx][ny]==1) {
				visited[nx][ny] = 1;
				s.push({nx, ny});
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	
	int cnt = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(arr[i][j]==1 && visited[i][j]==0) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
	
	return 0;
}