# 문제 17. 통신망 분석

예상 티어: 실버 2
예상 태그: 그래프 탐색, BFS, DFS

<br>

## 문제 설명

1번부터 N 번까지 N 개의 컴퓨터와 M 개의 양방향 통신 회선이 있다.
통신 회선을 통해 직/간접적으로 연결되어 있다면, 하나의 컴포넌트로 여긴다.
그중 가장 밀도가 높은 컴포넌트에 속한 컴퓨터의 번호를 오름차순으로 출력하는 문제다.

2 <= N <= 100000
1 <= M <= 200000
1 <= ai, bi <= N


<br>

## 문제 해결

그래프 탐색 이후 조건에 맞춰 정렬하는 문제다.
밀도가 높은 순, 컴퓨터 수가 적은 순, 작은 컴퓨터 번호 순으로 정렬기준을 만들면 된다.

```cpp
// 밀도에 내림차순, 컴퓨터 수에 오름차순, 최소 컴퓨터 번호에 오름차순
bool comp(piv a, piv b) {
	if(a.first * b.second.size() == b.first * a.second.size()) {
		if(a.second.size() == b.second.size()) {
			return a.second[0] < b.second[0];
		}
		
		return a.second.size() < b.second.size();
	}
	
	return a.first * b.second.size() > b.first * a.second.size();
}
```

그래프 탐색은 BFS를 통해 진행했다.
```cpp
void BFS(int x) {
	visited[x] = 1;
	queue<int> q;
	q.push(x);
	piv tmp = {0, {}};
	
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		// 컴퓨터 추가
		tmp.second.push_back(c);
		// 간선 더하기
		tmp.first += v[c].size();
		
		for(int i=0; i<v[c].size(); i++) {
			int n = v[c][i];
				
			if(visited[n]==0) {
				visited[n]=1;
				q.push(n);
			}
		}
	}
	// 컴퓨터 번호로 오름차순
	sort(tmp.second.begin(), tmp.second.end());
	// 양방향 간선이므로 2로 나눈다.
	tmp.first /= 2;
	
	ans.push_back(tmp);
}
```

기준에 맞춰 정렬한 후, 첫 컴포넌트의 컴퓨터를 출력한다.
```cpp
// 기준에 맞춰 정렬
sort(ans.begin(), ans.end(), comp);

for(int i=0; i<ans[0].second.size(); i++) {
	cout << ans[0].second[i] << " ";
}
```



<br>

## 문제 후기

가장 많이 만나는 문제 유형이라고 생각한다.
사실 다른 문제보다 어렵지만, 많이 접해서 정답률이 높다.
졸업과제를 준비한다고 바빠졌지만, 알고리즘을 포기할 수 없게 되었다.


<br>