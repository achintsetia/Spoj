#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char** argv)
{
  int N;
  scanf("%d", &N);
  int count = 0;
  for( int i=1; i<=N; i++)
    for( int j=i; i*j<=N; j++)
      count++;
  printf( "%d\n", count);
  return 0;
}
