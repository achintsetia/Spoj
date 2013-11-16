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
  long long int D;
  long long int F;
  long long int B;
  long long int M;

  long long int plots = 0;
  long long int spend = 0;

  scanf("%lld %lld %lld %lld", &D, &F, &B, &M);

  while( D > 0)
  {
    spend = (F*(F+1)/2 + 1)*B;

    if( D - spend >= M)
      printf("Farmer Cream will have %lld Bsf to spend.\n", D-spend);
    else
      printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", spend+M-D);

    scanf("%lld %lld %lld %lld", &D, &F, &B, &M);
  }
  return 0;
}
