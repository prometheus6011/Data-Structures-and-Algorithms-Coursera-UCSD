#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std ;

int get_majority_element( vector<int> &a ) {

    map<int, int> freq ;
    int n = a.size() ;

    for ( int i = 0; i < n; i++ ) {
        freq[a[i]]++ ;
    }

    for ( int i = 0; i < n; i++ ) {
        if (freq[a[i]] > n / 2) {
            return 1 ;
        }
    }

    return 0 ;
}

int main( ) {
  int n ;
  cin >> n ;
  vector<int> a(n) ;
  for ( size_t i = 0; i < a.size(); ++i ) {
    cin >> a[i];
  }
  cout << ( get_majority_element( a ) ) << '\n' ;
}