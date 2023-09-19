# 문제 19. 대체 경로

예상 티어: 실버 2
예상 태그: 그래프 탐색, BFS

<br>

## 문제 설명

1번부터 N번까지 N개의 도시와 M개의 도로가 주어진다.
S번 도시에서 E번 도시까지 최소한의 도시를 거치는 경로를 선택하여 이동할 때,
거쳐가는 도시의 수를 N번 출력하는 문제.

이때, i번째 출력하는 경우 i번 도로를 사용할 수 없다.
도착할 수 없을 경우 -1을 출력한다.

3 <= N <= 1000
N-1 <= M <= 2000
1 <= S, E <= N
1 <= u, v <= N

<br>

## 문제 해결

자세히 보면 이전 BFS문제들과 큰 차이가 없다.
i번이 속한 간선을 이용하지 않는다는 조건으로 BFS를 N번 사용하면 된다.
나는 visited 배열에 i번 도시를 이미 방문한 것으로 처리한 후 BFS를 시행했다.

```cpp
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
```

만약 출발 도시이거나 도착 도시이면 BFS를 할 필요 없이, 바로 -1을 출력했다.
```cpp
for(int i=1; i<=N; i++) {
	// 출발/도착 도시가 공사 중인 경우, 도달 불가
	if(S==i || E==i) {
		cout << "-1\n";
		continue;
	}
	BFS(i);
}
```


<br>

## 문제 후기

이제 마지막 한 문제가 남아있다.
카카오 테크 캠퍼스를 통해 크램폴린IDE를 쓰고 있는데,
뭔가 익숙한 기분이었다.


<br>