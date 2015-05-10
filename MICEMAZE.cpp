#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

int main() {
	int N, E, T, M;
	cin >> N >> E >> T >> M;
	int adjMat[N+1][N+1];
	memset(adjMat, 10000, sizeof(adjMat));
	//for(int i=1; i<=N; i++){
	//	for(int j=1; j<=N; j++){
	//			adjMat[i][j] = INT_MAX;
	//	}
	//}
	adjMat[E][E] = 0;
	for(int i=0; i<M; i++){
		int x, y, l;
		cin >> x >> y >> l;
		adjMat[x][y] = l;
	}
	
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
			}
		}
	}
	
	int count = 0;
	for(int i=1; i<=N; i++){
		if(adjMat[i][E] <= T){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}