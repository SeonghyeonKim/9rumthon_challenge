#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	string S;
	cin >> N >> S;
	
	vector<string> v;
	// 전체 N개의 문자를 i, j, N-i-j개로 나눈다
	// 부분 문자열로 나누어 벡터 v에 저장한다
	for(int i=1; i<=N-2; i++) {
		for(int j=1; j<=N-i-1; j++) {
			v.push_back(S.substr(0, i));
			v.push_back(S.substr(i, j));
			v.push_back(S.substr(i+j, N-i-j));
		}
	}
	
	// 부분 문자열을 오름차순으로 정렬한다
	sort(v.begin(), v.end());
	// 중복된 부분 문자열을 제거한다
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int si = v.size();
	map<string, int> m;
	// 문자열과 점수를 맵 m에 저장한다
	for(int i=0; i<si; i++) {
		m.insert({v[i], i+1});
	}
	
	// 부분 문자열의 점수가 제일 높은 분할의 점수를 구한다
	int ans = 0;
	for(int i=1; i<=N-2; i++) {
		for(int j=1; j<=N-i-1; j++) {
			ans = max(ans, m[S.substr(0, i)] + m[S.substr(i, j)] + m[S.substr(i+j, N-i-j)]);
		}
	}
	
	cout << ans;
	
	return 0;
}