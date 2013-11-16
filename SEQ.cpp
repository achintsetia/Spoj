#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define MOD 1000000000

typedef unsigned long long ull;

template< class T >
class Matrix
{
    public:
        int m,n;
        T *data;

        Matrix( int m, int n );
        Matrix( const Matrix< T > &matrix );

        const Matrix< T > &operator=( const Matrix< T > &A );
        const Matrix< T > operator*( const Matrix< T > &A );
        const Matrix< T > operator^( int P );

        ~Matrix();
};

template< class T >
Matrix< T >::Matrix( int m, int n )
{
    this->m = m;
    this->n = n;
    data = new T[m*n];
    for(int i=0; i<m*n; i++)
      data[i] = 0;
}

template< class T >
Matrix< T >::Matrix( const Matrix< T > &A )
{
    this->m = A.m;
    this->n = A.n;
    data = new T[m*n];
    for( int i = 0; i < m * n; i++ )
        data[i] = A.data[i];
}

template< class T >
Matrix< T >::~Matrix()
{
    delete [] data;
}

template< class T >
const Matrix< T > &Matrix< T >::operator=( const Matrix< T > &A )
{
    if( &A != this )
    {
        delete [] data;
        m = A.m;
        n = A.n;
        data = new T[m*n];
        for( int i = 0; i < m * n; i++ )
            data[i] = A.data[i];
    }
    return *this;
}

template< class T >
const Matrix< T > Matrix< T >::operator*( const Matrix< T > &A )
{
  Matrix C( m, A.n );
  for( int i = 0; i < m; ++i )
    for( int j = 0; j < A.n; ++j )
    {
      C.data[i*C.n+j]=0;
      for( int k = 0; k < n; ++k )
        C.data[i*C.n+j] = (C.data[i*C.n+j] + (data[i*n+k]*A.data[k*A.n+j]) % MOD)%MOD;
    }
  return C;
}

template< class T >
const Matrix< T > Matrix< T >::operator^( int P )
{
    if( P == 1 ) return (*this);
    if( P & 1 ) return (*this) * ((*this) ^ (P-1));
    Matrix B = (*this) ^ (P/2);
    Matrix C = B*B;
    return C;
}

int main( int argc, char** argv)
{
  int t;
  cin >> t;
  int n, k;
  int b[10];
  int c[10];

  for( int i=0; i<t; i++)
  {
    cin >> k;

    for(int i=k-1; i>=0; i--) cin >> b[i];
    for(int i=0; i<k; i++) cin >> c[i];

    cin >> n;

    Matrix<ull>  M(k, k);
    for(int i=0; i<k; i++) M.data[i] = c[i];

    for(int i=1; i<k; i++) M.data[i*k+i-1] = 1;

    if( n <= k)
      cout << b[n-1] << endl;
    else
    {
      M = M^(n-k);
#if 0
      for(int i=0; i<k; i++)
      {
        for(int j=0; j<k; j++)
          cout << M.data[i*k+j] << " ";
        cout << endl;
      }
#endif
      ull ans = 0;
      for(int i=0; i<k; i++)
        ans = (ans + (M.data[i]*b[i])%MOD) % MOD;
      cout << ans << endl;
    }
  }
  return 0;
}


