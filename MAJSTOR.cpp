#include <iostream>
#include <string.h>

using namespace std;

int main( int argc, char** argv)
{
  int R; cin >> R;
  string S; cin >> S;
  int num; cin >> num;
  int sc = 0;
  string fri[num];
  for(int i=0; i<num; i++)
  {
    cin >> fri[i];
    for( int j=0; j<R; j++)
      if( S[j] == fri[i][j]) sc++;
      else if ( (S[j] == 'S' && fri[i][j] == 'P')||
                (S[j] == 'P' && fri[i][j] == 'R')||
                (S[j] == 'R' && fri[i][j] == 'S')) sc += 2;
  }
  cout << sc << endl;

  string sym = "SPR";
  int highScore = 0;
  for( int j=0; j<R; j++)
  {
    int s[] = {0,0,0};
    for(int c=0; c<3; c++)
    {
      for(int i=0; i<num; i++)
      {
        if( sym[c] == fri[i][j]) s[c]++;
        else if ( (sym[c] == 'S' && fri[i][j] == 'P')||
                  (sym[c] == 'P' && fri[i][j] == 'R')||
                  (sym[c] == 'R' && fri[i][j] == 'S')) s[c] += 2;

      }
    }
    int M = max(max(s[0],s[1]),s[2]);
    highScore += M;
  }
  cout << highScore << endl;
  return 0;
}
