#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int table[2001][2001];

int editDistance(string A, string B){
  table[0][0] = 0;
  int M = A.size();
  int N = B.size();
  for(int i=1; i<=M; i++){
    table[i][0] = i;
  }

  for(int j=1; j<=N; j++){
    table[0][j] = j;
  }

  for(int i=1; i<=M; i++){
    for(int j=1; j<=N; j++){
      if(A[i-1] == B[j-1]){
        table[i][j] = table[i-1][j-1];
      }
      else{
        table[i][j] = min(table[i-1][j], table[i][j-1]) + 1;
        table[i][j] = min(table[i][j], table[i-1][j-1]+1);
      }
    }
  }
  return table[M][N];
}

int main( int argc, char** argv)
{
  int T;
  cin >> T;
  while(T--){
    string A, B;
    cin >> A;
    cin >> B;
    memset(table, 0, sizeof(table));

    cout << editDistance(A, B) << endl;
  }
  return 0;
}
