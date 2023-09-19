#include <iostream>
using namespace std;

int N, M;
// board[x][y][0]: x열 y행을 지나는 세로선의 수, board[x][y][1]: x열 y행을 지나는 가로선의 수
int board[103][103][2];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		
		// Up: 현재 칸 기준으로 위를 향하는 세로선 추가
		if(c=='U') {
			for(int i=x; i>0; i--) {
				board[i][y][0] += 1;
			}
		}
		// Down: 현재 칸 기준으로 아래를 향하는 세로선 추가
		else if(c=='D') {
			for(int i=x; i<=N; i++) {
				board[i][y][0] += 1;
			}
		}
		// Right: 현재 칸 기준으로 우측을 향하는 가로선 추가
		else if(c=='R') {
			for(int i=y; i<=N; i++) {
				board[x][i][1] += 1;	
			}
		}
		// Left: 현재 칸 기준으로 좌측을 향하는 가로선 추가
		else {
			for(int i=y; i>0; i--) {
				board[x][i][1] += 1;
			}
		}
	}
	
	// cnt: 중첩 점 수의 합
	long long cnt = 0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			// 각 칸을 지나가는 가로선과 세로선의 곱
			cnt += 1LL * board[i][j][0] * board[i][j][1];
		}
	}
	cout << cnt;
	
	return 0;
}


