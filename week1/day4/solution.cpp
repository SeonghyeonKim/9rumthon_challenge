#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, ans=0;
	cin >> N;
	
	int flag=1, tmp=0;
	for(int i=0; i<N; i++) {
		int a;
		cin >> a;
		
		if(flag) {
			if(a < tmp) flag=0;
			ans += a;
			tmp = a;
		}
		else {
			if(a > tmp) {
				cout << 0;
				return 0;
			}
			ans += a;
			tmp = a;
		}
	}
	
	cout << ans;
	
	return 0;
}