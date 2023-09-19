# 문제 12. 발전기

예상 티어: 실버 5
예상 태그: 깊이 우선 탐색, 너비 우선 탐색

<br>

## 문제 설명

N x N의 타일에 0, 1이 적혀있다.
상하좌우로 인접한 1은 연결되어있다고 했을때, 연결된 컴포넌트의 수를 출력해라.

1 <= N <= 1000

<br>

## 문제 해결

나는 BFS를 더 좋아해서 너비 우선 탐색을 통해 문제를 해결했다.

```cpp
// 연결된 칸 탐색
void bfs(int x, int y) {
	visited[x][y] = 1;
	queue<pii> q;
	q.push({x, y});
	
	while(!q.empty()) {
		pii c = q.front();
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];
			
			// 유효한 범위에 있고, 집이 있으며, 방문하지 않았을 경우
			if(nx>=0 && nx<N && ny>=0 && ny<N && visited[nx][ny]==0 && arr[nx][ny]==1) {
				visited[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
}
```


<br>

## 문제 후기

그래프 탐색의 대표적인 문제다.
DFS와 재귀를 통해 문제를 해결하려고 했으나, Runtime Error가 생겼다.
아마 재귀의 깊이가 overflow 난 듯 하다. (solution2.cpp)
stack을 통해 구현한 알고리즘은 잘 작동한다. (solution3.cpp)



<br>