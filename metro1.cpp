#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int K;
int points[1001][1001];
float memo[1001][1001];

float solve(int N, int M) {
  if(N < 0 || M < 0) return 1e9;
  else if(N == 0 && M == 0)
    return 0;
  else if(memo[N][M] != 0)
    return memo[N][M];
  else {
    if(points[N][M] == 1) {
      memo[N][M] = min(100.0+solve(N-1, M), min(100.0+solve(N, M-1), 100*sqrt(2.0)+solve(N-1, M-1)));
    }
    else {
      memo[N][M] = min(100.0+solve(N-1, M), 100.0+solve(N, M-1));
    }
    return memo[N][M];
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  cin >> K;
  for(int i=0; i<=N; ++i) {
    for(int j=0; j<=M; ++j) {
      memo[N][M] = 0;
    }
  }
  for(int i=0; i<K; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    points[t1][t2] = 1;
  }
  float ans = solve(N, M);
  cout << round(ans) << endl;
}
