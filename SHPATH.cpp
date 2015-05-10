#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int shortestPath(vector<pair<int,int> > adjList[], int N, int s, int d){
	if(s == d)
		return 0;
	bool visited[N];
	int dists[N];
	for(int i=0; i<N; i++){
		visited[i] = false;
		dists[i] = INT_MAX;
	}
	
	dists[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	Q.push(make_pair(0, s));

	while(!Q.empty()){
		int ui = Q.top().second;
		Q.pop();
		if(visited[ui]){
			continue;
		}
		for(int i=0; i<adjList[ui].size(); i++){
			int v = adjList[ui][i].second;
			int w = adjList[ui][i].first;
			if(!visited[v] && dists[ui] + w < dists[v]){
				dists[v] = dists[ui] + w;
				Q.push(make_pair(dists[v], v));
			}
		}
		
		if(ui == d) return dists[ui];
		
		visited[ui] = true;
	}
	
	return dists[d];
}

int main() {
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		map<string, int> cities;
		vector<pair<int, int> > adjList[N];
		for(int i=0; i<N; i++){
			string name;
			cin >> name;
			cities[name] = i;
			int K;
			cin >> K;
			for(int k=0; k<K; k++){
				int v, l;
				cin >> v >> l;
				v--;
				adjList[i].push_back(make_pair(l, v));
			}
		}
		
		int R;
		cin >> R;
		for(int r=0; r<R; r++){
			string from, to;
			cin >> from >> to;
			int s = cities[from];
			int d = cities[to];
			cout << shortestPath(adjList, N, s, d) << endl;
		}
	}
	return 0;
}