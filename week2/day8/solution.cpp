#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, ans=0;
	cin >> N;
	
	// painkiller 사용
	ans += N/14;
	N %= 14;
	
	// medicine 사용
	ans += N/7;
	N %= 7;
	
	// bandage 사용
	ans += N;
	
	cout << ans;
	
	return 0;
}