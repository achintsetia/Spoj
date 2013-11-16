#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define FASTIO 1

string decompose( int N)
{
  if(N == 0) return string("0");
  string res = string("");
  for( int i=31; i>=0; i--)
    if( (N>>i)&1 == 1)
    {
      if( i!=1)
        res += "2(" + decompose(i) + ")+";
      else if( i == 1)
        res += "2+";
    }
  return res;
}

int main( int argc, char** argv)
{
  int N;
  cin >> N;
  string res = decompose(N);
  string ans = string("");
  for( int i=0; i<res.size()-1; i++)
    if( res[i] == '+' && res[i+1] == ')')
      continue;
    else
      ans += res[i];

  cout << ans << endl;
  return 0;
}
