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
  int num;
  scanf("%d", &num);
  while( num != 42)
  {
    printf( "%d\n", num);
    scanf("%d", &num);
  }
  return 0;
}
