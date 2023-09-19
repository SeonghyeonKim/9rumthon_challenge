// 단순 구현을 통한 풀이

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, Ap, Bp;
	cin >> N >> Ap >> Bp;

	// 짝수와 짝수의 합은 홀수가 될 수 없음.
	if(Ap%2==0 && Bp%2==0 && N%2==1) {
		cout << -1;
		return 0;
	}

	// cnta: A 아이템의 수, cntb: B 아이템의 수
	int cnta = 0, cntb = N / Bp;
	while(cntb >= 0) {
		cnta = (N - cntb*Bp) / Ap;

		// 정확하게 통증 수치가 0인 경우
		if(cnta*Ap + cntb*Bp == N) {
			cout << cnta + cntb;
			return 0;
		}
		cntb--;
	}
	// 통증 수치가 0이 될 수 없는 경우
	cout << -1;

	return 0;
}