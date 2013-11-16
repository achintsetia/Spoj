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
  long double c;
  scanf( "%Lf", &c);

  while( c != 0.00)
  {
    int denom = 2;
    long double hang = 0.50;

    while( hang < c)
    {
      denom++;
      hang += 1.0/((long double) denom);
    }
    printf("%d card(s)\n", denom-1);

    scanf( "%Lf", &c);
  }

  return 0;
}
