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
  char a[1001], b[1001];
  while( scanf("%s %s", a, b) != EOF)
  {
    int histA[26]={0}, histB[26] = {0};
    int lenA = strlen(a);
    int lenB = strlen(b);

    for( int i=0; i<lenA; i++) histA[a[i]-'a']++;

    for( int i=0; i<lenB; i++) histB[b[i]-'a']++;

    string ans = "";

    for( int i=0; i<26; i++)
    {
      int minCount = min(histA[i], histB[i]);
      for( int j=0; j<minCount; j++)
        ans += (char) ('a'+i);
    }

    printf("%s\n", ans.c_str());
  }
  return 0;
}
