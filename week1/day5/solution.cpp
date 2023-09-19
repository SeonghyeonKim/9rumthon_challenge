#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b) {
	int aCnt=0, bCnt=0;
	for(int i=a; i; i>>=1) aCnt += (i&1);
	for(int i=b; i; i>>=1) bCnt += (i&1);
	
	if(aCnt == bCnt) return a > b;
	return aCnt > bCnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> v(N);
	for(int i=0; i<N; i++) cin >> v[i];
	
	sort(v.begin(), v.end(), comp);
	cout << v[K-1];
	
	return 0;
}