# 문제 20. 연결 요소 제거하기

예상 티어: 실버 1
예상 태그: 그래프 탐색, 시뮬레이션, BFS

<br>

## 문제 설명

N x N 크기의 2차원 배열에  알파벳 대문자 혹은 . 문자가 적혀있다.
상하좌우로 인접한 칸에 동일한 문자가 적혀있는 경우, 연결 되어있다고 한다.
(yi, xi) 칸에 대문자 di를 쓰고, K 개 이상의 연결이 되어있는 칸은 모두 . 문자로 교체하는 과정을
Q번 반복할 때, 배열에 적힌 문자를 출력하는 문제.


3 <= N <= 50
2 <= K <= 50
1 <= Q <= 1000
1 <= xi, yi <= N


<br>

## 문제 해결

yi xi di 가 입력 될 때마다, (yi, xi)에 di를 입력하고 그 칸을 시작으로 BFS를 시행한다.
```cpp
// Q번 입력 받을 때마다 BFS 시행
for(int i=0; i<Q; i++) {
	int x, y;
	char d;

	cin >> x >> y >> d;

	arr[x][y] = d;
	BFS(x, y);
}
```

시작 칸을 기준으로 연결된 요소를 벡터 v에 저장한다.
```cpp
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
```

v의 크기가 K 이상일 경우 v를 순회하면서 벡터에 속한 좌표의 값을 . 문자로 변경한다. 
```cpp
// 연결 요소가 K개 이상일 때
if(v.size()>=K) {
	for(int i=0; i<v.size(); i++) {
		arr[v[i].first][v[i].second] = '.';
	}
}
```


<br>

## 문제 후기

마지막 문제까지 풀었다.
슬프게도 1, 2, 3주차 이벤트에 당첨되지 못했다.
느낌상 4주차도 힘들 것 같다.
그래도 오프라인 이벤트에 희망을 걸고 있다.


<br>