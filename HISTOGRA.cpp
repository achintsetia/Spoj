#include <iostream>
using namespace std;
void max( long long int &a, long long int b) { if(a<b) a=b; }
long long int res;
#define MAX 100005
long long int V[MAX]; int N;
int l1[MAX]; 
int l2[MAX]; 
 
int fn(int *l)
{
  int s[MAX]; int st=0;
	V[0]=-1;
	s[0]=0;
	for(int i=1;i<=N;i++){
		while( V[s[st]] >= V[i] ){
			st--; 
		}
		l[i] = s[st];
		st++;
		s[st]=i; 
	} 
}
/*
3 1 0 5
3 5 0 1
5 1 1 1 1 7
5 1 1 1 1 2
5 7 1 1 1 1 
5 2 1 1 1 1 
5 2 1 1 1 0 
5 0 2 1 1 1  
2 0 0
5 1 3 2 4 1
0
*/
 
int main()
{
	long long int w,h;
	while(1){
		cin>>N;
		if(N==0) break;
		for(int i=1;i<=N;i++) cin >> V[i];
		res=0;
		fn(l1);
		for(int i=1,j=N,k;i<j;i++,j--) {
			k=V[i];
			V[i]=V[j];
			V[j]=k;
		}
		fn(l2);
		for(int i=1;i<=N;i++) 
			l1[i]=N+1-l1[i];
		res=0;
		for(int i=1;i<=N;i++) 
			{
				w=l1[N+1-i]-1-l2[i];
				h=V[i];
				max(res, w*h);
			}
				
		cout<<res<<endl;		
	}
	return 0;
}
