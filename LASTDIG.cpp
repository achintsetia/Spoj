#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int lastDig( int a, long long b)
{
  if( b == 0) return 1;
  else if( a == 0) return 0;
  else if( b == 1) return a%10;
  else if( b%2 == 0)
  {
    int l = lastDig(a,b/2)%10;
    return (l*l)%10;
  }
  else if( b%2 == 1)
    return (a * lastDig(a, b-1)) % 10;
}

int main( int argc, char** argv)
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int a;
    long long b;
    scanf("%d %lld", &a, &b);
    printf("%d\n", lastDig(a, b));
  }
  return 0;
}
