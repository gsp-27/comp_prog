/* The code uses simple interval scheduling algorithm
 * Refer to wikipedia for knowing what the algorithm is*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > intervals;

int solve(int n) {
	int i=0, cnt = 1;
	int j=i+1;
	while(i < n-1 && j < n) {
		if(intervals[j].first >= intervals[i].second+1) {
			cnt++;
			i = j;
			j = i+1;
		}
		else {
			j++;
		}
	}
	return cnt;
}

int main() {
	int n; cin >> n;
	for(int i=0; i<n; ++i) {
		int s, e;
		cin >> s >> e;
		pair<int, int> p;
		p.first = s;
		p.second = e;
		intervals.push_back(p);
	}
	// sort the vector based on the second element,i.e the ending time
	sort(intervals.begin(), intervals.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
		return left.second < right.second;
	});

	int ans = solve(n);
	cout << ans << endl;
	return 0;
}