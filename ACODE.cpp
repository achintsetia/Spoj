#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[50001];

long long intrepretations( string str, int start, int end)
{
  if( arr[start] > 0) return arr[start];

  if( str[start] == '0')
    return 0;

  if( start == end)
  {
    arr[start] = 1;
    return arr[start];
  }
  if( end-start == 1)
  {
    if( (str[start] == '1' || str[start] == '2') && str[start+1] == '0')
    {
      arr[start] = 1;
      arr[start+1] = 0;
      return arr[start];
    }
    else if( (str[start] == '1' && str[start+1] != '0') ||
        (str[start] == '2' && str[start+1] <= '6' && str[start+1] != '0'))
    {
      arr[start] = 2;
      arr[start+1] = 1;
      return arr[start];
    }
    else
    {
      if( arr[start+1] == 0)
        arr[start+1] = intrepretations( str, start+1, end);
      arr[start] = arr[start+1];
      return arr[start];
    }
  }
  else if( (str[start] == '1' && str[start+1] != '0') ||
        (str[start] == '2' && str[start+1] <= '6' && str[start+1] != '0'))
  {
    if( arr[start+1] == 0)
      arr[start+1] = intrepretations( str, start+1, end);
    if( arr[start+2] == 0)
      arr[start+2] = intrepretations( str, start+2, end);

    arr[start] = arr[start+1] + arr[start+2];
    return arr[start];
  }
  else if( (str[start] == '1' || str[start] == '2') && str[start+1] == '0')
  {
    if( arr[start+2] == 0)
      arr[start+2] = intrepretations( str, start+2, end);

    arr[start] = arr[start+2];
    return arr[start];
  }
  else
  {
    if( arr[start+1] == 0)
      arr[start+1] = intrepretations( str, start+1, end);

    arr[start] = arr[start+1];
    return arr[start];
  }
}

int main( int argc, char** argv)
{
  string str;
  cin >> str;

  while( str[0] != '0')
  {
    for( int i=0; i<5001; i++)
      arr[i] = 0;
    cout << intrepretations( str, 0, str.size()-1) << endl;
    cin >> str;
  }
  return 0;
}
