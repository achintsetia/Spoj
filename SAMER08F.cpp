#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int ans( int N)
{
  if( N == 1) return 1;
  if( N == 2) return 5;
  return N*N + ans(N-1);
}


int main( int argc, char** argv)
{
  int N;

  cin >> N;

  while(N != 0)
  {
    cout << (N*(N+1)*(2*N+1)) / 6 << endl;
    cin >> N;
  }
  return 0;
}
