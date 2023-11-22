#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std ;

struct Segment {
  int start, end ;
} ;

bool compare_segments(Segment a, Segment b) {
    return a.start < b.start ;
}

void print_struct( vector<Segment> &segments ) {
    for (int i=0; i<segments.size() ; i++ ) {
        cout << "Start: " << segments[i].start << endl ;
        cout << "End: " << segments[i].end << endl ;
    }
} 

vector<int> optimal_points( vector<Segment> &segments ) {
  vector<int> points ;
  int x = segments[0].end ;
  
  sort( segments.begin(), segments.end(), compare_segments) ;

  for( size_t i = 0; i < segments.size(); ++i ) {
    if(segments[i].start > x) {
        points.push_back(x) ;
        x = segments[i].end ;
    } else {
        x = min(x, segments[i].end) ;
    }
  }
  points.push_back( x ) ;
  return points ;
}

int main( ) {
  int n ;
  std::cin >> n ;
  vector<Segment> segments(n) ;
  for( size_t i = 0; i < segments.size(); ++i ) {
    std::cin >> segments[i].start >> segments[i].end ;
  }
  vector<int> points = optimal_points(segments) ;
  std::cout << points.size() << "\n" ;
  for( size_t i = 0; i < points.size(); ++i ) {
    std::cout << points[i] << " " ;
  }
}