#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int solve(int N, int K) {
	int ans, zeros, nzeros;
	ans = K-1;
	nzeros = K-1;
	zeros = 0;
	for(int i=2; i<=N; ++i) {
		ans = zeros*(K-1) + nzeros*K;
		zeros = nzeros;
		nzeros = ans-zeros;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int K, N;
	cin >> N >> K;

	int ans = solve(N, K);
	cout << ans << endl;
	return 0;
}