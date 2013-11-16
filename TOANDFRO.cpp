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
  int cols;
  string text;
  cin >> cols;

  while( cols != 0)
  {
    cin >> text;

    int rows = text.size() / cols;

    char arr[rows][cols];

    for( int i=0; i<rows; i++)
    {
      for( int j=0; j<cols; j++)
      {
        if( i % 2 == 0)
          arr[i][j] = text[i*cols + j];
        else
          arr[i][j] = text[i*cols + cols-(j+1)];
      }
    }
    for( int j=0; j<cols; j++)
      for( int i=0; i<rows; i++)
        cout << arr[i][j];
    cout << endl;

    cin >> cols;
  }
  return 0;
}
