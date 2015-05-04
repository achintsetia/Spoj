#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctype.h>

using namespace std;

char num[32];
int dp[32][256];

int solve(int pos, int prev, int N){
  if(pos >= N)
    return 1;

  if(dp[pos][prev] != -1){
    return dp[pos][prev];
  }

  int ret = 0;
  for(int i=pos, sum=0; i<N; i++){
    sum += num[i] - '0';
    if(sum >= prev){
      ret += solve(i+1, sum, N);
    }
  }
  dp[pos][prev] = ret;
  return ret;
}

int main( int argc, char** argv)
{
  int count = 1;
  while(scanf("%s", num) == 1 && isdigit(num[0])){
    memset(dp, -1, sizeof(dp));
    int len = strlen(num);
    printf("%d. %d\n", count++, solve(0, 0, len));
  }
  return 0;
}
