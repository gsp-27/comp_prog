#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
map<string, vector<string> > graph;
map<string, int> dist;

void bfs(string source) {
	queue<string> visited;
	map<string, vector<string> >::iterator it;
	it = graph.find(source);
	// Isenbaev is not present in any team so just return and
	// print undefined for everything
	if(it == graph.end()) return;

	// If Isebaev is present, mark the dist to it as 0
	dist[source] = 0;
	visited.push(source);
	while(!visited.empty()) {
		// get the first element and visit all its neighbors
		string current = visited.front();
		visited.pop();
		vector<string> neighbors = graph[current];
		for(int i=0; i<neighbors.size(); ++i) {
			if(dist[neighbors[i]] == -1) {
				dist[neighbors[i]] = dist[current] + 1;
				visited.push(neighbors[i]);
			}
		}
	}
	return;
}

int main(int argc, char* argv[]) {
	int n; cin >> n;
	for(int i=0; i<n; ++i) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		graph[s1].push_back(s2);
		graph[s1].push_back(s3);
		graph[s2].push_back(s1);
		graph[s2].push_back(s3);
		graph[s3].push_back(s1);
		graph[s3].push_back(s2);
	}
	map<string, vector<string> >::iterator it;
	for(it = graph.begin(); it != graph.end(); ++it) {
		dist[it->first] = -1;
	}
	bfs("Isenbaev");
	// map<string, vector<string> >::iterator it;
	// for(it=graph.begin(); it!=graph.end(); ++it) {
	// 	// it->second is a vector
	// 	cout << it->first << " "; 
	// 	vector<string> temp = it->second;
	// 	for(int i=0; i<temp.size(); ++i) {
	// 		cout << temp[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	map<string, int>::iterator i;
	for(i = dist.begin(); i!=dist.end(); ++i) {
		if(i->second == -1) {
			cout << i->first << " " << "undefined" << endl;
		}
		else {
			cout << i->first << " " << i->second << endl;
		}
	}
	return 0;
}
