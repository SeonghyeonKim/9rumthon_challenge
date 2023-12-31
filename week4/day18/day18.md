# 문제 18. 중첩 점

예상 티어: 실버 5
예상 태그: 구현

<br>

## 문제 설명

한 변의 길이가 N인 정사각형과 M 개의 반직선이 있다.
y x d이 주어질 때, y 번째 행의 x 번째 열에 해당하는 칸에서 d 방향으로 반직선을 긋는다.
반직선이 교차할 때 생기는 중첩 점의 개수를 출력하는 문제.

1 <= N <= 100
1 <= M <= 100000
1 <= xi, yi <= N
di는 U, D, L, R 중 하나이다.

<br>

## 문제 해결

단순 반복문 구현을 통해 문제를 해결했다.
y x d가 주어질 때마다 각 칸에 가로선, 세로 선의 개수를 증가시켰다.

```cpp
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
```

반복문을 종료하면, 각 칸을 순회하며 중첩점의 개수를 더했다.
```cpp
// cnt: 중첩 점 수의 합
long long cnt = 0;
for(int i=1; i<=N; i++) {
	for(int j=1; j<=N; j++) {
		// 각 칸을 지나가는 가로선과 세로선의 곱
		cnt += 1LL * board[i][j][0] * board[i][j][1];
	}
}
```

마지막 중첩 점의 개수를 int를 통해 구했는데, 마지막 테스트 케이스를 통과하지 못했다.
int 범위를 벗어날 수 있으므로 long long으로 타입을 설정했다.


<br>

## 문제 후기

이 풀이는 Q가 입력될 때마다 반복문을 실행한다.
Q가 커진다면 사용할 수 없다.
현재는 2방향(가로/세로)로 선을 구했는데,
imos법을 사용하여 4방향(U/D/L/R) 누적합을 사용하면 될 것 같다.


이제 2문제 남았다.
곧 학교 수업에도 과제가 생길 듯 하다.


<br>