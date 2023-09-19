#include <iostream>
#include <vector>
#include <algorithm>
#define pll pair<long long, long long>
using namespace std;

// Ci/Pi 값을 기준으로 내림차순 비교
bool comp(pll a, pll b) {
	return a.first * b.second < b.first * a.second;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long N, K;
	cin >> N >> K;
	
	// {Pi, Ci} 형식으로 저장
	vector<pll> v(N);
	for(long long i=0; i<N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	// Ci/Pi를 기준으로 내림차순 정렬
	sort(v.begin(), v.end(), comp);
	
	// cost: 현재 가진 돈, ans: 현재 얻은 포만감
	long long cost=K, ans=0;
	for(int i=0; i<N; i++) {
		// 돈이 없는 경우 
		if(cost==0) break;
		// 조각을 구매하는 경우
		if(cost < v[i].first) {
			ans += v[i].second / v[i].first * cost;
			break;
		}
		// 전체를 구매하는 경우
		cost -= v[i].first;
		ans += v[i].second;
	}
	
	cout << ans;
	
	return 0;
}