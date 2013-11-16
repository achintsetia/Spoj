#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char buf[10001];
char str[10001];

int main( int argc, char** argv)
{
  int T; cin >> T;
  char c = getchar();
  while( T--)
  {
    c = getchar();
    int bufSize = 0;
    map<string, int> strMap;
    while( c != '\n')
    {
      if( c == ' ')
      {
        if( bufSize > 0)
        {
          buf[bufSize] = '\0';
          //cout << buf << " ";
          strMap[string(buf)] = 1;
          bufSize = 0;
        }
      }
      else buf[bufSize++] = c;
      c = getchar();
    }

    if( bufSize > 0)
    {
      buf[bufSize] = '\0';
      //cout << buf << " ";
      strMap[string(buf)] = 1;
      bufSize = 0;
    }
    cout << strMap.size() << endl;
  }
  return 0;
}
