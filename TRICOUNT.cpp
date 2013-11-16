#include <stdio.h>

using namespace std;

int main( int argc, char** argv)
{
  unsigned long long arr[1000001];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 5;
  arr[3] = 13;
  arr[4] = 27;
  for(int i=5; i<=1000000; i++)
    arr[i] = 3*arr[i-1] - 2*arr[i-2] - 2*arr[i-3] + 3*arr[i-4] - arr[i-5];

  int T, N;
  scanf( "%d", &T);

  while(T--)
  {
    scanf("%d", &N);
    printf("%llu\n", arr[N]);
  }
  return 0;
}
