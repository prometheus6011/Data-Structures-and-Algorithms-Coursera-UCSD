#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std ;

void print_vector( vector<int> vec ) {
    for( int i = 0; i < vec.size( ); i++ ) {
        cout << vec[i] << " " ;
    }
}

int compute_min_refills( int dist, int tank, vector<int> & stops ) {
    stops.push_back( dist ) ;

    int tank_left = tank ;
    int count = 0 ;

    int prev_stop = 0 ;

    for( int i = 0; i < stops.size(); i++ ) {
        int distance = stops[i] - prev_stop ;
        if( distance <= tank_left ) {
            tank_left -= distance ;
        } else {
            if( distance > tank ) {
                return -1 ;
            } else {
                count++ ;
                tank_left = tank - distance ;
            }
        }
        prev_stop = stops[i] ;
    }

    return count ;
}


int main( ) {
    int d = 0 ;
    cin >> d ;
    int m = 0 ;
    cin >> m ;
    int n = 0 ;
    cin >> n ;

    vector<int> stops( n );
    for ( size_t i = 0; i < n; ++i )
        cin >> stops.at( i ) ;

    cout << compute_min_refills( d, m, stops ) << endl ;

    return 0 ;
}