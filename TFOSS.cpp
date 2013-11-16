#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO 1

#if FASTIO
/////////////////////
////// INPUT ////////
////////////////////
class INPUT {
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *bufend;
  void grabBuffer();
  public:
  INPUT() { grabBuffer(); }
  bool eof() { return bufend==buffer; }
  char nextChar() { return *bufpos; }
  inline char readChar();
  inline void skipWS();
  long long int readUnsigned();
  long long int readInt();
};

char INPUT::buffer[INPUT::BUFSIZE];

void INPUT::grabBuffer() {
  bufpos = buffer;
  bufend = buffer + fread( buffer, 1,BUFSIZE,stdin);
}

char INPUT::readChar() {
  char res = *bufpos++;
  if(bufpos==bufend) grabBuffer();
  return res;
}

inline bool myisspace(char c) { return c<=' '; }

void INPUT::skipWS() {
  while(!eof() && myisspace(nextChar())) readChar();
}

long long INPUT::readUnsigned() {
  skipWS();
  long long res = 0;
  while(!eof() && isdigit(nextChar())) {
    res = 10u * res + (readChar()-'0');
  }
  return res;
}

long long int INPUT::readInt() {
  skipWS();
  bool neg = false;
  if(!eof() && nextChar()=='-') { neg=true; readChar(); }
  long long int res = static_cast<long long int>(readUnsigned());
  if(neg) res = -res;
  return res;
}

/////////////////////
////// OUTPUT //////
////////////////////

class OUTPUT {
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *BUFLIMIT;
  void flushBuffer();
  public:
  OUTPUT():bufpos(buffer),BUFLIMIT(buffer+BUFSIZE-100) {}
  ~OUTPUT() { flushBuffer(); }
  inline void operator()(char c);
  inline void operator()(unsigned x);
  inline void operator()(int x);
  inline void operator()(unsigned long long int x);
  inline void operator()(long long int x);
  inline void operator()(const char*s);
  void operator()(const string&s) { operator()(s.c_str()); }
  template<class A,class B>
    void operator()(const A& a,const B& b) {
      operator()(a); operator()(b);
    }
  template<class A,class B,class C>
    void operator()(const A& a,const B& b,const C&c) {
      operator()(a); operator()(b); operator()(c);
    }
  template<class A,class B,class C,class D>
    void operator()(const A& a,const B& b,const C&c,const D&d) {
      operator()(a); operator()(b); operator()(c); operator()(d);
    }
  template<class A,class B,class C,class D,class E>
    void operator()(const A& a,const B& b,const C&c,const D&d,const E&e) {
      operator()(a); operator()(b); operator()(c); operator()(d); operator()(e);
    }
  template<class A,class B,class C,class D,class E,class F>
    void operator()(const A& a,const B& b,const C&c,const D&d,const E&e,const F&f) {
      operator()(a); operator()(b); operator()(c); operator()(d); operator()(e); operator()(f);
    }
};

char OUTPUT::buffer[OUTPUT::BUFSIZE];

void OUTPUT::flushBuffer() {
  char *p = buffer;
  while(p < bufpos) {
    p += fwrite( p,1, bufpos-p,stdout);
  }
  bufpos = buffer;
}

void OUTPUT::operator()(char c) {
  *bufpos = c;
  ++bufpos;
  if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(unsigned x) {
  char *old = bufpos;
  do {
    *bufpos = char('0' + x % 10u);
    x /= 10u;
    ++bufpos;
  } while(x);
  reverse(old, bufpos);
  if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(int x) {
  if(x<0) { operator()('-'); x = -x; }
  operator()(static_cast<unsigned>(x));
}

void OUTPUT::operator()(unsigned long long int x) {
  char *old = bufpos;
  do {
    *bufpos = char('0' + x % 10u);
    x /= 10u;
    ++bufpos;
  } while(x);
  reverse(old, bufpos);
  if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(long long int x) {
  if(x<0) { operator()('-'); x = -x; }
  operator()(static_cast<unsigned long long int>(x));
}

void OUTPUT::operator()(const char*s) {
  while(*s) operator()(*s++);
}

INPUT input;
OUTPUT output;

#endif

typedef long long int lli;
#define pii pair<lli, lli>


pii points[100001];

lli cross(pii P,pii Q,pii R)//if return >0 then point R is upper of lineseg PQ else down
{
  return  (Q.first-P.first)*(R.second-P.second)-(R.first-P.first)*(Q.second-P.second);
}

void hull( pii P[], int N, vector<pii>& L, vector<pii>& U)
{
  sort(P, P+N);
  int j=0,k=0,n=N;
  U.resize(2*n);
  L.resize(2*n);
  for(int i=0;i<n;i++)
  {
    while(j>=2 && cross(L[j-2],L[j-1],P[i])<=0)//p[i] is making right turn we need left turn
      j--;
    while(k>=2 && cross(U[k-2],U[k-1],P[i])>=0)//p[i] is making left turn we need right
      k--;
    L[j++]=P[i];
    U[k++]=P[i];
  }
  U.resize(k);
  L.resize(j);
}

lli fun(pair<lli,lli> P ,pair<lli,lli> Q)
{
  return (P.first-Q.first)*(P.first-Q.first)+(P.second-Q.second)*(P.second-Q.second);
}

int main( int argc, char** argv)
{
  int T = input.readInt();

  while( T--)
  {
    int N = input.readInt();

    for( int i=0; i<N; i++)
    {
      int A = input.readInt();
      int B = input.readInt();
      points[i] = make_pair(A,B);
    }

    if( N == 1)
    {
      output("0\n");
      continue;
    }

    vector<pii> L;
    vector<pii> U;
    hull(points, N, L, U);

    int i=0,j,m;
    j=L.size()-1;
    m=U.size()-1;
    lli maxDist=-1;
    while(i<m || j>0)
    {
      maxDist=max(maxDist,fun(U[i],L[j]));
      if(i==m)
        j--;
      else if(j==0)
        i++;
      else
      {
        if ( (U[i+1].second-U[i].second) * (L[j].first-L[j-1].first) > (L[j].second-L[j-1].second) * (U[i+1].first-U[i].first) )
          i++;
        else
          j--;
      }
    }
    output(maxDist, "\n");
  }
  return 0;
}
