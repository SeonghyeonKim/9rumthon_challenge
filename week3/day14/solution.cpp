#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, cnt;
int visited[2001];
vector<int> edge[2001];

// 재귀를 이용한 DFS
void dfs(int idx, int cnt) {
	int si = edge[idx].size();
	
	for(int i=0; i<si; i++) {
		int nextIdx = edge[idx][i];
		
		if(visited[nextIdx]==0) {
			visited[nextIdx] = 1;
			dfs(nextIdx, cnt+1);
		}
	}
	
    // 더 이상 갈 곳이 없는 경우, 돌아가지 않고 답을 출력한 후 프로그램 종료
	cout << cnt << " " << idx;
	exit(0);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
    // 번호가 제일 작은 노드가 앞에 오도록 정렬 
	for(int i=1; i<=N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	
	visited[K] = 1;
	dfs(K, 1);
	
	return 0;
}