#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

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

#define pii pair<int, int>
#define f first
#define s second

pii arr[100001];

// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
    passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
    current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(pii *st, int ss, int se, int qs, int qe, int index, int* minIndex)
{
  // If segment of this node is a part of given range, then return the
  // min of the segment

  //cout << "RQ: " << ss << " " << se << " " << qs << " " << qe << endl;
  if (qs <= ss && qe >= se)
  {
    *minIndex = st[index].s;
    return st[index].f;
  }


  // If segment of this node is outside the given range
  if (se < qs || ss > qe)
    return INT_MAX;

  // If a part of this segment overlaps with the given range
  int indA = 0, indB = 0;
  int mid = getMid(ss, se);
  int A = RMQUtil(st, ss, mid, qs, qe, 2*index+1, &indA);
  int B = RMQUtil(st, mid+1, se, qs, qe, 2*index+2, &indB);
  if( A < B)
  {
    *minIndex = indA;
    return A;
  }
  else
  {
    *minIndex = indB;
    return B;
  }
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(pii *st, int n, int qs, int qe, int* index)
{
  // Check for erroneous input values
  if (qs < 0 || qe > n-1 || qs > qe)
  {
    printf("Invalid Input");
    return -1;
  }

  return RMQUtil(st, 0, n-1, qs, qe, 0, index);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(pii arr[], int ss, int se, pii *st, int si, int* index)
{
  // If there is one element in array, store it in current node of
  // segment tree and return
  if (ss == se)
  {
    st[si].f = arr[ss].f;
    st[si].s = ss;
    *index = ss;
    return arr[ss].f;
  }

  // If there are more than one elements, then recur for left and
  // right subtrees and store the minimum of two values in this node
  int indA=0, indB=0;
  int mid = getMid(ss, se);
  int A = constructSTUtil(arr, ss, mid, st, si*2+1, &indA);
  int B = constructSTUtil(arr, mid+1, se, st, si*2+2, &indB);
  if( A < B)
  {
    st[si].f = A;
    st[si].s = indA;
    *index = indA;
  }
  else
  {
    st[si].f = B;
    st[si].s = indB;
    *index = indB;
  }
  return st[si].f;
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
pii *constructST(pii arr[], int n)
{
  // Allocate memory for segment tree
  int x = (int)(ceil(log2(n))); //Height of segment tree
  int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
  pii *st = new pii[max_size];

  // Fill the allocated memory st
  int temp = 0;
  constructSTUtil(arr, 0, n-1, st, 0, &temp);

  // Return the constructed segment tree
  return st;
}

long long maxArea( pii* st, int N, int start, int end)
{
  if( end < start) return -1;
  if( start < 0) return -1;
  if( end < 0) return -1;
  if( start > N-1) return -1;
  if( end > N-1) return -1;
  if( start == end) return arr[start].f;

  int minIndex = 0;
  int Min = RMQ(st, N, start, end, &minIndex);


  long long Max = (long long) Min*(end-start+1);

  //cout << " "<< Max <<" " << Min <<" " << (end-start+1)<< endl;

  if( minIndex > start)
    Max = max(Max, maxArea( st, N, start, minIndex-1));

  if( minIndex < end)
    Max = max(Max, maxArea( st, N, minIndex+1, end));

  //cout << start << " " << end << " " << minIndex << " " << arr[minIndex].f << " " << Max << endl;

  return Max;
}

long long largestRectArea( int N)
{
  pii* st = constructST( arr, N);

  long long retVal = 0;
  retVal = maxArea( st, N, 0, N-1);
  delete[] st;
  return retVal;
}

int main( int argc, char** argv)
{

  int N = input.readInt();
  while(N > 0)
  {
    for(int i=0; i<N; i++)
    {
      arr[i].f = input.readInt();
      arr[i].s = i;
    }

    output(largestRectArea(N), "\n");
    N = input.readInt();
  }
  return 0;
}
