#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

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

#define SIZE(a) ((int)a.size())
int const INF = 0x3f3f3f3f;

struct state
{
  int x, c;
  state() { x = c = 0; }
  state(int _x, int _c)
    : x(_x), c(_c) {}
  bool operator < (const state &s) const {
    return c > s.c;
  }
};

struct edge
{
  int u,v,w;
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
};

vector<edge> edges;
vector< vector<state> > G;
vector< vector<state> > H;
vector< vector<state> > I;
vector<int> distFromS;
vector<int> distFromT;
vector<int> distFinal;

bool visited[550];

void dijkastra( vector< vector<state> >& GR, int src, vector<int>& dist)
{
  dist = vector<int> ( SIZE(GR), INF);
  memset( visited, false, sizeof(visited));
  dist[src] = 0;
  priority_queue<state> q;

  q.push( state(src, 0));

  while( !q.empty())
  {
    int indx = q.top().x;
    int cost = q.top().c;
    q.pop();

    if( visited[indx]) continue;

    visited[indx] = true;

    for( int i=0; i<SIZE(GR[indx]); i++)
    {
      int newc = cost + GR[indx][i].c;
      if( newc < dist[GR[indx][i].x])
      {
        dist[GR[indx][i].x] = newc;
        q.push( state( GR[indx][i].x, newc));
      }
    }
  }
}

int main( int argc, char** argv)
{
  while(1)
  {
    int N = input.readInt();
    int M = input.readInt();

    if( N+M == 0) break;

    int S = input.readInt();
    int D = input.readInt();

    G = vector< vector<state> > (N);
    H = vector< vector<state> > (N);
    I = vector< vector<state> > (N);

    for( int i=0; i<M; i++)
    {
      int U = input.readInt();
      int V = input.readInt();
      int P = input.readInt();

      edges.push_back( edge( U, V, P));

      G[U].push_back( state( V, P));
      H[V].push_back( state( U, P));
    }

    dijkastra( G, S, distFromS);
    dijkastra( H, D, distFromT);

    if( distFromS[D] == INF)
    {
      distFromT.clear();
      distFromS.clear();
      for( int i=0; i<N; i++)
      {
        G[i].clear();
        H[i].clear();
      }
      G.clear();
      H.clear();
      edges.clear();

      output( "-1\n");
      continue;
    }

    for( int i=0; i<M; i++)
    {
      if( distFromS[edges[i].u] + edges[i].w + distFromT[edges[i].v] != distFromS[D])
        I[edges[i].u].push_back( state(edges[i].v, edges[i].w));
    }

    dijkastra( I, S, distFinal);

    if( distFinal[D] >= INF) output("-1\n");
    else output(distFinal[D], "\n");

    distFromT.clear();
    distFromS.clear();
    distFinal.clear();

    for( int i=0; i<N; i++)
    {
      G[i].clear();
      H[i].clear();
      I[i].clear();
    }
    G.clear();
    H.clear();
    I.clear();
    edges.clear();
  }
  return 0;
}
