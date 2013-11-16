#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;

unsigned long long reverse( unsigned long long num)
{
  int temp = num;

  while( temp % 10 == 0) temp /= 10;

  string rev = "";
  while(temp > 10)
  {
    rev += '0' + temp%10;
    temp /= 10;
  }
  rev += '0' + temp;

  return atoll(rev.c_str());
}

int main( int argc, char** argv)
{
  int N;
  cin >> N;

  while(N--)
  {
    unsigned long long num1, num2;
    cin >> num1 >> num2;

    while( num1 % 10 == 0) num1/=10;
    while( num2 % 10 == 0) num2/=10;

    cout << reverse( reverse(num1) + reverse(num2)) << endl;
  }
  return 0;
}
