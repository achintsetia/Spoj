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
  unsigned long long N;
  scanf("%lld", &N);

  if( (N&(N-1)) == 0)
    printf("TAK\n");
  else
    printf("NIE\n");
  return 0;
}
