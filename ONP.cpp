#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;


int main( int argc, char** argv)
{
  map<char, int> opPriority;
  opPriority['('] = 0;
  opPriority['+'] = 1;
  opPriority['-'] = 2;
  opPriority['*'] = 3;
  opPriority['/'] = 4;
  opPriority['^'] = 5;

  int T;
  cin >> T;

  while(T--)
  {
    string expr;
    cin >> expr;

    string res = "";
    stack<char> st;
    for( int i=0; i<expr.size(); i++)
    {
      if( expr[i] == '(')
        st.push('(');
      else if( expr[i] == ')')
      {
        while( st.top() != '(')
        {
          res+= st.top();
          st.pop();
        }
        st.pop();
      }
      else if( expr[i] >= 'a' && expr[i] <= 'z')
        res += expr[i];
      else
      {
        if( opPriority[expr[i]] > opPriority[st.top()])
          st.push(expr[i]);
        else
        {
          res+=st.top();
          st.pop();
          st.push(expr[i]);
        }
      }
    }

    cout << res << endl;
  }
  return 0;
}
