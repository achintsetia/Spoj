#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int shortestPath(vector<pair<int, int> > adjList[], int N, int s, int d){
	bool visited[N];
	int dists[N];
	for(int i=0; i<N; i++){
		visited[i] = false;
		dists[i] = INT_MAX;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	Q.push(make_pair(0, s));
	dists[s] = 0;
	
	while(!Q.empty()){
		pair<int,int> x = Q.top();
		Q.pop();
		int ui = x.second;
		int wi = x.first;
		if(visited[ui])
			continue;
		
		
		for(int i=0; i<adjList[ui].size(); i++){
			int vi = adjList[ui][i].second;
			int w = adjList[ui][i].first;
			if(!visited[vi] && dists[ui] + w < dists[vi] ){
				dists[vi] = dists[ui] + w;
				Q.push(make_pair(dists[vi], vi));
			}
		}
		visited[ui] = true;
	}
	return dists[d];
}

int main() {
	int T;
	cin >> T;
	while(T--){
		int M, N;
		cin >> M >> N;
		int Map[M][N];
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cin >> Map[i][j];
			}
		}
		
		int x, y, t;
		cin >> x >> y >> t;
		x--; y--;
		int s = 0;
		int d = x*N+y;
		t -= Map[0][0];
		
		vector<pair<int, int> > adjList[M*N];
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				int w = i*N+j;
				if(i<M-1){
					adjList[w].push_back(make_pair(Map[i+1][j], (i+1)*N+j));
				}
				if(i>0){
					adjList[w].push_back(make_pair(Map[i-1][j], (i-1)*N+j));
				}
				if(j>0){
					adjList[w].push_back(make_pair(Map[i][j-1], i*N+j-1));
				}
				if(j<N-1){
					adjList[w].push_back(make_pair(Map[i][j+1], i*N+j+1));
				}
			}
		}
		int ans = shortestPath(adjList, M*N, s, d);
		if(ans > t){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			cout << t-ans << endl;
		}
	}
	return 0;
}