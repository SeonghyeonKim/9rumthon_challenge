// dp를 통한 풀이

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, Ap, Bp;
	cin >> N >> Ap >> Bp;
	
	// dp[k]: 현재 통증 수치가 k일 경우, 사용하는 아이템의 최소 개수
	vector<int> dp(1000001, 987654321);
	dp[0] = 0;
	
	for(int i=0; i<=N; i++) {
		if(i-Ap >= 0) dp[i] = min(dp[i], dp[i-Ap]+1);
		if(i-Bp >= 0) dp[i] = min(dp[i], dp[i-Bp]+1);
	}
	// 0이 되지 못할 경우
	if(dp[N]==987654321) cout << -1;
	else cout << dp[N];
	
	return 0;
}