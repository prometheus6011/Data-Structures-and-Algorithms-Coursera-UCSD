#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std ;

vector<int> pisano( int mod, int& count ) {
    vector<int> original ;
    int a = 0 ;
    int b = 1 ;
    int temp ;

    original.push_back(a) ;
    original.push_back(b) ;

    for(int i = 2; i < mod * mod; i++) {
        temp = (a + b) % mod ;
        a = b % mod ;
        b = temp ;
        original.push_back(b) ;
        count++ ;
        if( (a == 0) && (b == 1) ) {
            return original ;
        }
    }
    return original ;
}

int fibonacci_sum_squares( long long n, vector<int> vec, int& count ) {
    if ( n % count <= 1 )
        return n % count ;

    int sum = 1 ;

    for (long long i = 2; i <= n % count; ++i) {
        sum += vec[i] * vec[i] ;
    }

    return sum % 10 ;
}

int main() {
    long long n = 0;
    cin >> n ;
    int count = 0 ;
    int &ref_count = count ;
    vector<int> vec = pisano( 10, ref_count ) ;
    cout << fibonacci_sum_squares( n, vec, ref_count ) << endl ;
}