#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

void initialize( unsigned int *, const unsigned int );
void show_list( const unsigned int *, const unsigned int );
void criba( unsigned int *, const unsigned int );
void setItem ( unsigned int *, const unsigned int, const unsigned int );

bool IsPrime(const unsigned int x)
{
  const unsigned int TOP
  = static_cast<int>(
      std::sqrt( static_cast<double>( x ) )
    ) + 1;

  for ( int i=2; i != TOP; ++i )
  {
    if (x % i == 0) return false;
  }
  return true;
}

int main()
{

    unsigned int *l;
    unsigned int n;

    cout << "Ingrese tope de criba" << endl;
    cin >> n;

    l = new unsigned int[n];

    initialize( l, n );

    cout << "Esta es la lista" << endl;
    show_list( l, n );

    criba( l, n );  

    cout << "Estos son los primos" << endl;
    show_list( l, n );
}

void initialize( unsigned int *l, const unsigned int n)
{
    for( int i = 0; i < n - 1; i++ )
        *( l + i ) = i + 2;
}

void show_list( const unsigned int *l, const unsigned int n)
{
    for( int i = 0; i < n - 1; i++ )
    {
        if( *( l + i ) != 0)
            cout << l[i] << " - ";
    }
    cout << endl;
}

void setItem( unsigned int *l, const unsigned int n, const unsigned int p)
{
    unsigned int i = 2;
    while( p * i <= n)
    {
        *( l + (i * p - 2) ) = 0;
        i++;
    }
}

void criba( unsigned int *l, const unsigned int n)
{
    for( int i = 0;  i * i <= n ; i++ )
     if( IsPrime ( *( l + i) ) )
        setItem( l, n, *(l + i) );      
}
