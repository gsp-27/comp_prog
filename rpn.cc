#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char* argv[]) {
	int t; cin >> t;
	for(; t--; ) {
		string s;
		cin >> s;
		stack <char> memo;
		int i=0;
		while(i < s.size()) {
			if(isalpha(s[i])) {
				cout << s[i];
				i++;
			}
			if(s[i] == ')') {
				while(memo.top() != '(') {
					cout << memo.top();
					memo.pop();
				}
				memo.pop();
			}
			else {
				memo.push(s[i]);
			}
			i++;
		}
		cout << endl;
	}
	return 0;
}
