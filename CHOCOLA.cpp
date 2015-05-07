#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		int M, N;
		cin >> M >> N;
		int xCuts[M-1];
		int yCuts[N-1];
		for(int i=0; i<M-1; i++){
			cin >> xCuts[i];
		}
		
		for(int i=0; i<N-1; i++){
			cin >> yCuts[i];
		}
		
		sort(xCuts, xCuts+M-1, greater<int>());
		sort(yCuts, yCuts+N-1, greater<int>());
		
		int xDone = 0;
		int yDone = 0;
		int i=0, j=0;
		long long ans = 0;
		while(i<M-1 || j<N-1){
			if(i<M-1 && j<N-1){
				if(xCuts[i] > yCuts[j]){
					ans += xCuts[i]*(yDone+1);
					i++;
					xDone++;
				}
				else{
					ans += yCuts[j]*(xDone+1);
					j++;
					yDone++;
				}
			}
			else{
				if(i<M-1){
					ans+= xCuts[i]*(yDone+1);
					i++;
					xDone++;
				}
				else{
					ans+= yCuts[j]*(xDone+1);
					j++;
					yDone++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}