#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if ( n <= 2 ) {
    summands.push_back( n ) ;
    return summands ;
  }

  int p = 1 ;
  while( n > 0 ) {
    n -= p ;
    if ( (p + 1) > n ) {
        int p_last = p + n ;
        summands.push_back( p_last ) ;
        n = 0 ;
    } else {
        summands.push_back( p ) ;
        p++ ;
    }
  }

  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}