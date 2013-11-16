#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

unsigned long int Solve( unsigned long int Num)
{
  unsigned long int num = Num;
  unsigned long int ans = num%2;
  for( int i=1; i<32; i++)
  {
    num >>= 1;
    if( num == 0) break;
    else
      ans = (num&1) | (ans<<1);
  }

  return ans;
}

int main( int argc, char** argv)
{
  unsigned long int N, num;

  cin >> N;

  for( int i=0; i<N; i++)
  {
    cin >> num;
    if( num%2 == 0)
      printf("%lu\n", Solve(num));
    else
      printf("%lu\n", num);
  }
  return 0;
}
