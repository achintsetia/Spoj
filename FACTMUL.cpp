#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull factmul1[10000001];
ull factmul2[10000001];

#define MOD1  186583
#define MOD2  587117
unsigned long long MOD=109546051211ULL;

ull e1 = (ull) 166628*MOD2;
ull e2 = (ull) 649909*MOD1;

int main( int argc, char** argv)
{
  ull n;
  cin >> n;
  if( n >= MOD2)
  {
    cout << 0 << endl;
    return 0;
  }

  factmul1[0] = 1; factmul1[1] = 1;
  factmul2[0] = 1; factmul2[1] = 1;
  for(ull i=2; i<=n; i++)
  {
    factmul1[i] = (factmul1[i-1]*i)%MOD1;
    factmul2[i] = (factmul2[i-1]*i)%MOD2;
  }
  for(ull i=2; i<=n; i++)
  {
    factmul1[i] = (factmul1[i-1]*factmul1[i])%MOD1;
    factmul2[i] = (factmul2[i-1]*factmul2[i])%MOD2;
  }
  ull ans = 0;
  ans = (ull) (ans + factmul1[n]*e1) % MOD;
  ans = (ull) (ans + factmul2[n]*e2) % MOD;
  cout << ans << endl;
  return 0;
}
