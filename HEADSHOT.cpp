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
  string arr;
  cin >> arr;

  int safeToShoot = 0;
  int safeToRotate = 0;
  int s = arr.length();
  for( int i=0; i<s; i++)
  {
    if( arr[i] == '0' && arr[(i+1)%s] == '0')
      safeToShoot++;
    else if( arr[i] == '0' && arr[(i+1)%s] == '1')
      safeToRotate++;
  }

  if( safeToRotate > 0)
  {
    if( safeToRotate == safeToShoot)
      cout << "EQUAL" << endl;
    else if( safeToRotate > safeToShoot)
      cout << "ROTATE" << endl;
    else if( safeToRotate < safeToShoot)
      cout << "SHOOT" << endl;
  }
  else
    cout << "EQUAL" << endl;

  return 0;
}
