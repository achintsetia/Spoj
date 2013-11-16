#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int gcd( int a, int b)
{
  if( b == 0) return a;
  else return gcd(b, a%b);
}

int main( int argc, char** argv)
{
  int T;
  cin >> T;
  string a,b;

  while(T--)
  {
    cin >> a >> b;

    int la = a.size();
    int lb = b.size();

    int g = gcd(la, lb);

    bool ans = true;
    if( g != la && g != lb)
    {
      for( int i=0; i<g; i++)
      {
        if( !ans) break;
        for( int k=0; k<la/g; k++)
          if( a[i] != a[i+k*g]) {ans = false; break;}
      }
      for( int i=0; i<g; i++)
      {
        if( !ans) break;
        for( int k=0; k<lb/g; k++)
          if( a[i] != b[i+k*g]) {ans = false; break;}
      }
    }
    else
    {
      if( la > lb)
      {
        for( int i=0; i<g; i++)
        {
          if( !ans) break;
          for( int k=0; k<la/g; k++)
            if( b[i] != a[i+k*g]){ ans = false; break; }
        }
      }
      else
      {
        for( int i=0; i<g; i++)
        {
          if( !ans) break;
          for( int k=0; k<lb/g; k++)
            if( a[i] != b[i+k*g]){ ans = false; break; }
        }
      }
    }
    if( ans ) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
