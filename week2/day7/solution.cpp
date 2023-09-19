#include <iostream>
using namespace std;

int board[1003][1003];
// 8방향 이동 범위
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,-1,0,1,-1,0,1,-1};

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
	
	int cnt = 0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			// 구름이 없는 칸일 때,
			if(board[i][j]==0) {
				// tmp : 현재 칸에서 인접한 구름의 수
				int tmp = 0;
				
				// 8방향으로 구름 확인
				for(int t=0; t<8; t++) {
					if(board[i+dx[t]][j+dy[t]]==1) tmp++;
				}
				
				if(tmp == K) cnt++;
			}
		}
	}
	cout << cnt;
	
	return 0;
}