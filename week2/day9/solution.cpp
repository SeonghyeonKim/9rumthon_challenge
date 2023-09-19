#include <iostream>
using namespace std;

// 각 칸의 땅의 상태.
char board[203][203];
// 각 칸의 폭탄 값.
int cnt[203][203];
// 폭탄이 떨어지는 칸.
int dx[] = {1,0,-1,0,0};
int dy[] = {0,-1,0,1,0};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> board[i][j];	
		}
	}
	
	for(int t=0; t<K; t++) {
		int y, x;
		cin >> y >> x;
		
		// 폭탄이 떨어진 곳을 기준으로 인접 칸 확인
		for(int i=0; i<5; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			// 땅의 상태에 따라 폭탄 값 증가
			if(board[ny][nx]=='@') cnt[ny][nx] += 2;
			else if(board[ny][nx]=='0') cnt[ny][nx] += 1;
		}
	}
	
	// 폭탄 값의 최대값 구하기
	int ans = 0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			ans = max(ans, cnt[i][j]);
		}
	}
	cout << ans;
	
	return 0;
}