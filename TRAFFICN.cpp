#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
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

#define MAX_DIST 1000000000

struct edge
{
  int v;
  int w;
};

vector<edge> G[10001];
vector<edge> H[10001];

enum color {white, gray, black};

void dijkastra( vector<edge>* graph, int size, int* d, int s)
{
  for( int i=1; i<=size; i++)
    d[i] = MAX_DIST;

  vector<color> c(size+1, white);
  d[s]=0;
  c[s]=gray;
  priority_queue<pair<int,int>, vector<pair<int,int> >,less<pair<int,int> > > q; // declare priority_queue
  q.push(make_pair(d[s],s)); //push starting vertex

  while(!q.empty())
  {
    //for( int i=1; i<=size; i++)
    //  cout << d[i] << " ";
    //cout << endl;


    int u=q.top().second;q.pop(); //pop vertex from queue
    //cout << "u: "<< u << endl;
    if(c[u]==black)continue;

    c[u]=black;

    for(int i=0;i<graph[u].size();i++)
    {
      int v=graph[u][i].v, w=graph[u][i].w;
      if(c[v] == white) //new vertex found
      {
        d[v]=d[u]+w;
        c[v]=gray;
        q.push(make_pair(d[v],v)); //add vertex to queue
      }
      else if(c[v]==gray && d[v]>d[u]+w) //shorter path to gray vertex found
      {
        d[v]=d[u]+w;
        q.push(make_pair(d[v],v)); //push this vertex to queue
      }
    }
  }
}

int main( int argc, char** argv)
{
  int T = input.readInt();

  while( T--)
  {
    int N = input.readInt();
    int M = input.readInt();
    int k = input.readInt();
    int s = input.readInt();
    int t = input.readInt();

    for( int i=1; i<=N; i++)
    {
      G[i].clear();
      H[i].clear();
    }

    for( int i=0; i<M; i++)
    {
      int di = input.readInt();
      int ci = input.readInt();
      int li = input.readInt();

      edge temp;

      temp.v = ci; temp.w = li;
      G[di].push_back(temp);

      temp.v = di; temp.w = li;
      H[ci].push_back(temp);
    }

    int distFromS[N+1];
    int distFromT[N+1];

    dijkastra(G, N, distFromS, s);
    dijkastra(H, N, distFromT, t);


    int minDist = distFromS[t];
    for( int j=0; j<k; j++)
    {
      int uj = input.readInt();
      int vj = input.readInt();
      int qj = input.readInt();

      minDist = min( distFromS[uj] + qj + distFromT[vj], minDist);

      minDist = min( distFromS[vj] + qj + distFromT[uj], minDist);
    }

    if( minDist >= MAX_DIST) output( -1, "\n");
    else output( minDist, "\n");
  }
  return 0;
}
