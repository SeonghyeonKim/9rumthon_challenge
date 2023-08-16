#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T, ans=0;
	cin >> T;
	
	while(T--) {
		int a, c;
		char b;
		
		cin >> a >> b >> c;
		
		switch(b) {
			case '+':
				ans += a+c;
				break;
			case '-':
				ans += a-c;
				break;
			case '*':
				ans += a*c;
				break;
			case '/':
				ans += a/c;
				break;
		}
	}
	
	cout << ans;
	
	return 0;
}