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

#define MAXN 100001

int dp[MAXN][2];

int vertexCover(vector<int> adj[], int N, int s, int p, int selected){

  if(dp[s][selected] != -1)
    return dp[s][selected];

  vector<int> ad = adj[s];

  if(!selected){
    int ans = 0;
    for(int j=0; j<ad.size(); j++){
      if(ad[j] != p)
        ans += vertexCover(adj, N, ad[j], s, 1);
    }
    dp[s][selected] = ans;
    return ans;
  }
  else{
    int ans = 0;
    for(int j=0; j<ad.size(); j++){
      if(ad[j] != p)
        ans += min(vertexCover(adj, N, ad[j], s, 1), vertexCover(adj, N, ad[j], s, 0));
    }
    ans += 1;
    dp[s][selected] = ans;
    return ans;
  }
}

int main( int argc, char** argv)
{
  int N = input.readInt();
  vector<int> adj[N];
  for(int i=0; i<N-1; i++){
    int v = input.readInt();
    int w = input.readInt();
    v--, w--;
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

  memset(dp, -1, sizeof(dp));
  output(min(vertexCover(adj, N, 0, -1, 1), vertexCover(adj, N, 0, -1, 0)), "\n");
  return 0;
}
