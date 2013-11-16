#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

int main( int argc, char** argv)
{
  int b[3] = {0};

  char c;
  int s = 0, ns = 1;
  int wickets = 0;
  while( scanf("%c", &c) != EOF)
  {
    if( wickets <= 1)
    {
      if( c >= '0' && c <= '9')
      {
        b[s] += (int) (c - '0');
        if( ((int)(c - '0'))%2 == 1)
        {
          int temp = s;
          s = ns;
          ns = temp;
        }
      }
      else if( c == 'O')
      {
        wickets++;
        if( wickets == 1)
          s = 2;
      }
    }
  }

  for( int i=0; i<3; i++)
    printf("%d\n", b[i]);

  return 0;
}
