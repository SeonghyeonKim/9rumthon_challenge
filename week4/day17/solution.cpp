#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define piv pair<int, vector<int> >
using namespace std;

int N, M;
// v[i]: i로 시작하는 간선을 표현하는 인접 리스트
vector<int> v[200001];
bool visited[200001];
// ans.first: 간선의 수, ans.second: 컴포넌트에 속한 컴퓨터 번호 벡터
vector<piv> ans;

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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1; i<=N; i++) {
		if(visited[i]==0) {
			BFS(i);
		}
	}
	
	// 기준에 맞춰 정렬
	sort(ans.begin(), ans.end(), comp);

	for(int i=0; i<ans[0].second.size(); i++) {
		cout << ans[0].second[i] << " ";
	}
	
	return 0;
}