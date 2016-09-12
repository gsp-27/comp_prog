#include <iostream>
#include <sstream>
using namespace std;
typedef unsigned long long ull;

ull memo[46];
// finding the nth fibonacci number where for n=1 and 2 we have the answer as 2
ull solve(int n) {
	if(n == 0) return 0;
	if(n == 1) return 2;
	if(memo[n] != 0) return memo[n];
	else {
		memo[n] = solve(n-1) + solve(n-2);
		return memo[n];
	}
}

int main(int argc, char* argv[]) {
	int n; cin >> n;
	for(int i=2; i<=n; ++i) memo[i] = 0;
	ull ans = solve(n);
	cout << ans << endl;
	return 0;
}
