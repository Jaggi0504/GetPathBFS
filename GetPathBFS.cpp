#include<bits/stdc++.h>
using namespace std;

vector<int> *getPathBFS(int **edges, int n, bool *visited, int s, int e) {
	if(s == e) {
		visited[s] = true;
		vector<int> *ans = new vector<int>;
		ans->push_back(s);
		return ans;
	}
	queue<int> q;
	bool done = false;
	vector<int> *output = new vector<int>;
	unordered_map<int, int>map;
	q.push(s);
	visited[s] = true;
	map[s] = -1;
	while(!q.empty() && !done) {
		int front = q.front();
		q.pop();for(int i=0;i<n;i++) {
			if(edges[front][i] == 1 && !visited[i]) {
				q.push(i);
				map[i] = front;
				visited[i] = true;
				if(i == e) {
					done = true;
					break;
				}
			}
		}
	}
	if(done) {
		for(int i=e;i!=-1;) {
			output->push_back(i);
			i = map.at(i);
		}
		return output;
	} else {
		return NULL;
	}
}

int main() {
	int n, e;
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cin>>f>>s;
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	int sv, ev;
	cin>>sv>>ev;
	vector<int> *output = getPathBFS(edges, n, visited, sv, ev);
	if(output != NULL) {
		for(int i=0;i<output->size();i++) {
			cout<<output->at(i)<<" ";
		}
	} else {
		return NULL;
	}
	return 0;
}
