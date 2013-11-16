#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int main( int argc, char** argv)
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    ull k, num;
    scanf("%llu", &k);
    printf("%llu\n", (k-1)*250+192);
  }
  return 0;
}
