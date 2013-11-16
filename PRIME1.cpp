#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int sieve[32000] = {0};
int primes[10000];

int array[100001] = {0};
int pCount = 0;

void init()
{
  int i, j;
  for( i=0; i<32000; i++)
      sieve[i] = 1;

  for( i=2; i<180; i++)
    if ( sieve[i])
      for( j=i; j*i<32000; j++)  sieve[i*j] = 0;

  for( i=2; i<32000; i++)
    if( sieve[i]) primes[pCount++] = i;
}

int main( int argc, char** argv)
{
  int T, M, N;
  int pNum;
  int i, j;
  init();

  scanf("%d", &T);

  while( T--)
  {
    memset(array , 0 , sizeof( array));

    scanf("%d %d", &M, &N);

    if( M < 2) M = 2;

    for( i=0; i<pCount; i++)
    {
      pNum = primes[i];

      if( pNum > (sqrt(N) + 1)) break;

      j = (pNum >= M) ? 2*pNum : M + (pNum - M%pNum)%pNum;

      for( ; j<=N; j+=pNum)
        array[j-M] = 1;
    }

    for( i=M; i<=N; i++) if( array[i-M] == 0) printf( "%d\n", i);
    printf( "\n");
  }
  return 0;
}
