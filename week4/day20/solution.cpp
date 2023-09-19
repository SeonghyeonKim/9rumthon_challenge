#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int N, K, Q;
char arr[53][53];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void BFS(int x, int y) {
	// 방문했던 좌표 기록
	vector<vector<int> > visited(N+3, vector<int> (N+3, 0));
	
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = 1;
	// 연결되어 있는 요소의 좌표
	vector<pii> v;
	
	while(!q.empty()) {
		pii c = q.front();
		q.pop();
		v.push_back(c);
		
		for(int i=0; i<4; i++) {
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];
			
			// 방문한 적이 없고 같은 문자일 경우
			if(visited[nx][ny]==0 && arr[nx][ny]==arr[c.first][c.second]) {
				visited[nx][ny]=1;
				q.push({nx, ny});
			}
		}
	}
	
	// 연결 요소가 K개 이상일 때
	if(v.size()>=K) {
		for(int i=0; i<v.size(); i++) {
			arr[v[i].first][v[i].second] = '.';
		}
	}
}
	
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K >> Q;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> arr[i][j];
		}
	}
	
	// Q번 입력 받을 때마다 BFS 시행
	for(int i=0; i<Q; i++) {
		int x, y;
		char d;
		
		cin >> x >> y >> d;
		
		arr[x][y] = d;
		BFS(x, y);
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}