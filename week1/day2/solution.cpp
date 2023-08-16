#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, T, M;
	cin >> N >> T >> M;
	
	int minute = T*60 + M;
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		
		minute = (minute + tmp) % 1440;
	}
	
	cout << minute/60 << " " << minute%60;
	
	return 0;
}