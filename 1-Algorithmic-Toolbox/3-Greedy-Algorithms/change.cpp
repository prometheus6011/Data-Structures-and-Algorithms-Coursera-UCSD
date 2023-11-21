#include <iostream>
#include <stdlib.h>
using namespace std ;

int get_change( int m ) {
  int numCoins = 0 ;

    while ( m != 0 ) {
        if( m >= 10 ) {
            numCoins++ ;
            m -= 10 ;
        } else if ( m >= 5 ) {
            numCoins++ ;
            m -= 5 ;
        } else if ( m >= 1 ) {
            numCoins++ ;
            m -= 1 ;
        }
    }

  return numCoins ;
}

int main( ) {
  int m ;
  cin >> m ;
  cout << get_change( m ) << endl ;
}