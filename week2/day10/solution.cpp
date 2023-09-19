#include <iostream>
#include <string>
#include <vector>
using namespace std;

string board[203][203];
int visited[203][203];
int N, Rg, Cg, Rp, Cp;

// x, y에서 시작했을 때, 지나간 칸 수 반환.
int findMap(int x, int y) {
	int cnt = 1;
	visited[x][y] = 1;
	while(1) {
		int count;
		char command;
		
		// 1 <= count <= 9 
		if(board[x][y].size()==2) {
			count = int(board[x][y][0] - '0');	
			command = board[x][y][1];
		}
		// 10 <= count <= 99
		if(board[x][y].size()==3) {
			count = int(board[x][y][0] - '0')*10 + int(board[x][y][1] - '0');
			command = board[x][y][2];
		}
		// 100 <= count <= 200
		if(board[x][y].size()==4) {
			count = int(board[x][y][0] - '0')*100 + int(board[x][y][1] - '0')*10 + int(board[x][y][2] - '0');
			command = board[x][y][3];
		}
		
		
		for(int i=0; i<count; i++) {
			if(command=='U') x--;
			if(command=='D') x++;
			if(command=='R') y++;
			if(command=='L') y--;

			// 범위를 넘어갔을 경우
			if(x==0) x = N;
			if(x==N+1) x = 1;
			if(y==0) y = N;
			if(y==N+1) y = 1;
			
			// 지나간 칸 일 경우
			if(visited[x][y]==1) {
				return cnt;
			}
			visited[x][y] = 1;
			cnt++;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> Rg >> Cg >> Rp >> Cp;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> board[i][j];
		}
	}
	
	// 구름이 지나간 칸 수
	int cntg = findMap(Rg, Cg);
	
	// visited 배열 초기화
	for(int i=0; i<=N; i++) {
		for(int j=0; j<=N; j++) {
			visited[i][j] = 0;
		}
	}

	// 플레이어가 지나간 칸 수
	int cntp = findMap(Rp, Cp);
	
	if(cntg >= cntp) cout << "goorm " << cntg;
	else cout << "player " << cntp;
	
	return 0;
}
