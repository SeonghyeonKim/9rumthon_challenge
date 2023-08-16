include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int W, R;
	cin >> W >> R;

	cout << int(W * (1 + R*1.0/30));

	return 0;
}
