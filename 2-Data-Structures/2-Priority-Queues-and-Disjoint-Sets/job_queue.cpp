#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>

using namespace std ;

class JobQueue {

  int num_threads ;
  vector<int> jobs ;

  vector<int> assigned_threads ;
  vector<long long> start_time ;

  void WriteResponse( ) {
    for ( int i = 0; i < jobs.size( ); i++ ) {
      cout << assigned_threads[i] << " " << start_time[i] << endl ;
    }
  }

  void ReadData( ) {
    int m ;
    cin >> num_threads >> m ;

    jobs.resize(m) ;

    for ( int i = 0; i < m; i++ ) {
      cin >> jobs[i] ;
    }
  }

  void AssignJobs( ) {
    assigned_threads.resize( jobs.size() ) ;
    start_time.resize( jobs.size() ) ;

    auto comp = []( const pair<int, long long> left, const pair<int, long long> right ) {
      if ( left.second == right.second ) {
        return ( left.first > right.first ) ;
      } else {
        return ( left.second > right.second ) ;
      }
    } ;

    priority_queue<pair<int, long long>, vector<pair<int, long long> >, decltype(comp)> thread_finish_time(comp) ;

    for( int i = 0; i < jobs.size(); i++ ) {
      int duration = jobs[i] ;
      int next_thread = 0 ;

      pair<int, long long> min_thread_finish_time_pair ;

      if ( thread_finish_time.size() < num_threads ) {
        min_thread_finish_time_pair = make_pair(i, 0) ;
      } else {
        min_thread_finish_time_pair = thread_finish_time.top( ) ;
        thread_finish_time.pop( ) ;
      }

      next_thread = min_thread_finish_time_pair.first ;

      assigned_threads[i] = next_thread ;
      start_time[i] = min_thread_finish_time_pair.second ;
      thread_finish_time.push( make_pair(next_thread, (min_thread_finish_time_pair.second + duration)) ) ;
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
