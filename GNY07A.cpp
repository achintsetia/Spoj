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
  int T; cin >> T;
  int num;
  string str;
  for(int i=1; i<=T; i++)
  {
    cin >> num >> str;

    printf("%d ", i);
    for( int j=0; j<str.size(); j++)
      if( j != num-1) printf("%c", str[j]);
    printf("\n");
  }
  return 0;
}
