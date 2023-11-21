#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std ;

int get_max_index( int n, vector<int> values, vector<int> weights ) {

	int max_index = -1 ;
	double max_ratio = 0.0 ;

	for ( int i = 0; i < n; i++ ) {

		double ratio = (double) values[i] / weights[i] ;

		if ( weights[i] != 0 && ratio > max_ratio ) {
			max_index = i ;
			max_ratio = ratio ;
		}
	}

	return max_index ;
}


double get_optimal_value( int n, int capacity, vector<int> weights, vector<int> values ) {

	double loot = 0.0 ;

	for ( int i = 0; i < n; ++i ) {

		if ( capacity == 0 )
			return loot ;

		int max_index = get_max_index( n, values, weights ) ;
		int a = min( weights[max_index], capacity ) ;
		loot +=  a * ( (double) values[max_index] / weights[max_index] ) ;
		capacity -= a ;
		weights[max_index] -= a ;
	}

  return loot ;
}

int main() {
  int n ;
  int capacity ;
  cin >> n >> capacity ;
  vector<int> values(n) ;
  vector<int> weights(n) ;
  for ( int i = 0; i < n; i++ ) {
    cin >> values[i] >> weights[i] ;
  }

  double optimal_value = get_optimal_value( n, capacity, weights, values ) ;

  cout.precision(10) ;
  cout << optimal_value << endl ;
  return 0;
}